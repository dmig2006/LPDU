#include "validparceljpeg.h"

//СКЛЕИВАНИЕ UDP ПОСЫЛОК В КАДР И ПРОВЕРКА КАДРА ДАЛЕЕ ОТПРАВЛЯЕТСЯ НА ОТРИСОВКУ

validParcelJPEG::validParcelJPEG(QObject *parent) : QObject(parent)
{
    sizeByte = 0;
    indexArrFrame = 0;
    epilogStartByte = 0;
    badFrames = 0;

    fStartFrame = false; fGoodHeader   = false;
    fStopFrame  = false; fGoodEpilog   = false;
    fStopByte   = false; fGoodSize     = false;
    flagEndKadr = false; fGoodNumFrame = false;

    jpegFrame = new QByteArray;
    jpegFrame->clear();
    header.clear();
    buffer.clear();
    epilog.clear();
}

validParcelJPEG::~validParcelJPEG()
{

}

void validParcelJPEG::reciveParcelJPEG(QByteArray frame)
{
    //header.clear();
    sizeFrame = frame.size();

    //ПОИСК ЗАГАЛОВКА
    //12 байт - заголовок кадра;
    //8 байт-идентификатор заголовка "HRKontur" 48 52 4B 6F 6E 74 75 72;
    //4 байта-циклический счётчик кадров- циклический 1 байтный счётчик, диапазон от 0 до 255, 00 00 00 II;
    if (!fGoodHeader)
    {
        //newLogMsg("header");
        for (int i = 0; i<12; i++)
        {
            if (i < 8)
            {
                header.append(frame[i]);    //заголовка кадра HRKontur
                if (i == 7)
                {
                    if (header == "HRKontur") {fGoodHeader = true;/*newLogMsg("header G");*/fStopFrame = false;}
                    else                      {fGoodHeader = false;/*newLogMsg("header B");*/fStopFrame = true;}
                    header.clear();
                }
            }
            if ((i >= 8) and (i < 12))           //поиск счётчика кадров в UDP посылке
            {
                countFramesStart.append(frame[i]); //счётчика кадров
            }

        }

   }
    //Конец поиска Загаловка


    //СОСТАВЛЕНИЕ КАДРА
    //JPEG-кадр начинается с маркера JPEG "FF D8",
    //заканчивается маркером “FF D9"
    if ((fGoodHeader) and (!fStopFrame))
    {
        //newLogMsg("starting frame");
        for (int i = 0; i < sizeFrame; i++)
        {
            if (sizeByte >= 2) sizeByte++;
            if ((fStartFrame) and (!fStopFrame)) // запись кадра от стартового до стопового
            {
                jpegFrame->append(frame[i]);
            }
            if ((frame[i] == 0xFF)) //поиск начала маркера FF
            {
                if (frame[i+1] == 0xD8)                                    //поиск стартового маркера D8
                {
                    jpegFrame->append(frame[i]);//запись первого байта в кадре
                    fStartFrame = true;
                    fStopByte   = false;
                    sizeByte = 2; //присвоение счётчику байтов в кадре 2, за начальный маркер FF D8

                }
                if (frame[i+1] == 0xD9)                                    //поиск конечного маркера D9
                {
                    jpegFrame->append(frame[i+1]);//запись последнего байта в кадре
                    fStartFrame = false;
                    flagEndKadr = true;
                    fStopFrame  = true;

                    if ((sizeByte % 4) == 0)  alignBytes = 0;   //расчёт количества выранивающих байтов до кратного 4 в кадре
                    else alignBytes = ((4-(sizeByte%4))%4);
                    epilogStartByte = (i+1) + alignBytes + 1;        //вычисление начального индекса эпилога в кадре
                    break;
                }
            }

        }
        if (jpegFrame->size() > 900000)
        {
            fGoodHeader = false;
            //newLogMsg("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
            fStopFrame = true;
            jpegFrame->clear();
        }

    }
    //Конец составления КАДРА

    //ПОИСК ЭПИЛОГА
    //16 байт-эпилог кадра;
    //8 байт-идентификатор эпилога "KonturFR" 4B 6F 6E 74 75 72 46 52;
    //4 байта-циклический счётчик кадров -значение должно совпадать со значением в заголовке  00 00 00 II;
    //4 байта - длина кадра (размер кадра в байтах) - значение N в сетевом порядке байт (big-endian) XX XX XX XX.
    if (flagEndKadr)                                     //анализ эпилога
    {
        //newLogMsg("starting epilog");
        for (int i=epilogStartByte;i <= epilogStartByte + 7;i++) {epilog.append(frame[i]);}           //заголовок эпилога
        for (int i=epilogStartByte+8;i <= epilogStartByte + 11;i++) {countFramesStop.append(frame[i]);}   //счётчик кадров в эпилоге
        for (int i=epilogStartByte+12;i <= epilogStartByte + 15;i++) {countBytesEndFrame.append(frame[i]);} //размер кадра в байтах

        if (epilog == "KonturFR")                                                                                        fGoodEpilog   = true;
        if ((sizeByte) == (countBytesEndFrame.toHex().toInt(&flagCountFrame,16)))                                       fGoodSize     = true;
        if ((countFramesStart.toHex().toInt(&flagCountFrame,16)) == (countFramesStop.toHex().toInt(&flagCountFrame,16))) fGoodNumFrame = true;

        flagEndKadr = false;

    }
    if ((!fStartFrame) and (fStopFrame))
    {
        //newLogMsg("starting veryfication");
        fStartFrame = false;
        fStopFrame  = false;
        epilogStartByte = 0;

        if ((fGoodHeader) and (fGoodEpilog) and (fGoodSize) and (fGoodNumFrame))
        {
            emit sendFrameJpeg(*jpegFrame);
            emit startDraw();
            //newLogMsg("good");
            /*newLogMsg(QString("\n\rРазмер кадра = %1 \n\r"
                              "Размер кадра = %3\n\r"
                             "Номер Кадра  = %2").arg(countBytesEndFrame.toHex().toInt(&flagCountFrame,16))
                                                  .arg(countFramesStop.toHex()   .toInt(&flagCountFrame,16)).arg(sizeByte));*/
            int i = countFramesStop.toHex().toInt(&flagCountFrame,16);
            double k = static_cast<double>(sizeByte)*25*8/1024/1024;
            double m = static_cast<double>(sizeByte)*25/1024/1024;
            emit sendDataOfFrame(sizeByte, k, m, i, badFrames);
            jpegFrame->clear();
            epilog.clear();
            countFramesStop.clear();
            countBytesEndFrame.clear();
            countFramesStart.clear();
            fGoodHeader   = false;
            fGoodEpilog   = false;
            fGoodSize     = false;
            fGoodNumFrame = false;

            sizeByte = 0;
        }
        else
        {
            //newLogMsg("Битый кадр");
            badFrames++;
            fGoodHeader   = false;
            fGoodEpilog   = false;
            fGoodSize     = false;
            fGoodNumFrame = false;
            sizeByte = 0;
            jpegFrame->clear();
            epilog.clear();
            countFramesStop.clear();
            countBytesEndFrame.clear();
            countFramesStart.clear();
        }
    }
}
    //Конец поиска Эпилога

