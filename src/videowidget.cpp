#include "videowidget.h"
#include "ui_videowidget.h"

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui -> setupUi(this);
    udpServer = new Udp_Server;
    clientTcp = new Client_Tcp;
    validJPEG = new validParcelJPEG;
    udpServer -> start();

    flagMode = true;
    flagInversia = false;
    f_on_640x480 = false;

    connect(clientTcp, SIGNAL(newLogMsg(QString)), this, SIGNAL(newLogMsg(QString)));
    connect(udpServer, SIGNAL(sendParcelJPEG(QByteArray)), validJPEG, SLOT(reciveParcelJPEG(QByteArray)));

    connect(validJPEG, SIGNAL(newLogMsg(QString)), this, SIGNAL(newLogMsg(QString)));
    connect(validJPEG, SIGNAL(sendFrameJpeg(QByteArray)), this, SLOT(jpegFrame(QByteArray)));
    connect(validJPEG, SIGNAL(startDraw()), this, SLOT(drawPicture()));

    ui -> list_log -> hide();
    ofOnListLog(false);

}

VideoWidget::~VideoWidget()
{
    if (udpServer -> isFinished())
    {
        delete ui;
        delete clientTcp;
        delete udpServer;
        delete validJPEG;
    }
}

void VideoWidget::camOperationMode()
{
//    flagMode = true;
    clientTcp -> sendTcpCmd(CAM_START);
}

void VideoWidget::camTestMode()
{
//    flagMode = false;
    clientTcp -> sendTcpCmd(CAM_STOP);
}

void VideoWidget::ofOnListLog(bool pFlag)
{
    if (pFlag)
    {
        ui -> helpEdit -> show();
        ui -> listHelp -> show();
//        ui -> list_log -> show();
    }
    else
    {
        ui -> helpEdit -> hide();
        ui -> listHelp -> hide();
//        ui -> list_log->hide();
    }
}

void VideoWidget::helpList(QString pString)
{
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem -> setText(/*num + QString("> ") +*/ pString);
    ui -> listHelp -> insertItem(0, newItem);

}

void VideoWidget::logText(QString pString)
{
    QListWidgetItem *newItem = new QListWidgetItem;
    newItem -> setText(/*num + QString("> ") +*/ pString);
    ui -> list_log -> insertItem(0, newItem);
//    ui -> listHelp -> insertItem(0, newItem);
}

void VideoWidget::camZoomNorma()
{
    clientTcp ->sendTcpCmd(CAM_Znorm);
//    logText("norma");
}

void VideoWidget::camZoomX2()
{
    clientTcp -> sendTcpCmd(CAM_Z2x);
//    logText("X2");
}

void VideoWidget::camZoomX4()
{
    clientTcp -> sendTcpCmd(CAM_Z4x);
//    logText("X4");
}

void VideoWidget::picture_640x480()
{
    if (!f_on_640x480) clientTcp -> sendTcpCmd(CAM_640x480);
    f_on_640x480 = true;
//    emit newLogMsg("640x480");
}

void VideoWidget::picture_800x600()
{
    clientTcp -> sendTcpCmd(CAM_800x600);
    f_on_640x480 = false;
//    emit newLogMsg("800x600");
}

void VideoWidget::picture_1024x768()
{
    clientTcp -> sendTcpCmd(CAM_1024x768);
    f_on_640x480 = false;
    //    emit newLogMsg("1024x768");
}

void VideoWidget::picture_1280x1024()
{
    clientTcp -> sendTcpCmd(CAM_1280x1024);
    f_on_640x480 = false;
}

void VideoWidget::picture_1920x1080()
{
    clientTcp -> sendTcpCmd(CAM_1920x1080);
    f_on_640x480 = false;
//    emit newLogMsg("1920x1080");
}

void VideoWidget::inversia(bool pInversia)
{
    if (pInversia)
    {
        emit newLogMsg("инверсия");
        flagInversia = true;
    }
    else
    {
        emit newLogMsg("Нормальный режим");
        flagInversia = false;
    }
}

void VideoWidget::jpegFrame(QByteArray jF)
{
    pixmapPicture.loadFromData(jF,"JPG");
}

void VideoWidget::drawPicture()
{
/*    QPixmap z;

    int x,y;
    x = 0;y=0;

    x = pixmapPicture.dotsPerMeterX();
    y = pixmapPicture.dotsPerMeterY();

    QString str;

    str = "Гор"+QString::number(x)+"Верт"+QString::number(y);
    logText(str);
*/
    if (flagMode)
    {
//        ui -> picture -> show();
//        ui -> picture -> resize(1366,768);
        ui -> picture -> setPixmap(QPixmap::fromImage(pixmapPicture));
//        ui -> picture -> move(0,0);

        ui -> picture -> setScaledContents(true);
        ui -> picture -> show();
//        ui -> picture -> resize(1366,768);
//        ui -> picture -> setPixmap(QPixmap::fromImage(pixmapPicture).scaled(ui->picture->size(),Qt::KeepAspectRatio));

    }
    else
    {
        ui -> picture -> hide();
        //ui -> picture -> move(280,-50);
//        if (flagInversia) ui -> picture -> setStyleSheet(COLOR_LABEL_INVERSIA_DATA);
//        else              ui -> picture -> setStyleSheet(COLOR_LABEL_NORMA_DATA);
        //ui -> picture -> setText("Дежурный режим");
    }
}
