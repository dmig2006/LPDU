#ifndef VALIDPARCELJPEG_H
#define VALIDPARCELJPEG_H

#include <QObject>
#include "udp_server.h"

class validParcelJPEG : public QObject
{
    Q_OBJECT
public:
    explicit validParcelJPEG(QObject *parent = 0);
    ~validParcelJPEG();
    QByteArray *jpegFrame;
signals:
    void newLogMsg (QString);
    void sendFrameJpeg (QByteArray);
    void startDraw();
    void sendDataOfFrame (int, double, double ,int, int);


public slots:
    void reciveParcelJPEG (QByteArray);

private:
    long sizeByte,indexArrFrame;
    bool fStartFrame, fStopFrame, fStopByte;

    QByteArray  header, epilog, countFramesStart, countFramesStop, countBytesEndFrame, buffer;
    int         sizeFrame, alignBytes, epilogStartByte, badFrames;
    bool        flagCountFrame, flagStartJPEG, flagStopJPEG, flagEndKadr;
    bool        fGoodHeader, fGoodEpilog, fGoodSize, fGoodNumFrame;
};

#endif // VALIDPARCELJPEG_H
