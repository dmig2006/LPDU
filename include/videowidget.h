#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QImage>
#include <QWidget>

#include "client_tcp.h"
#include "parcels_irzcam.h"
#include "udp_server.h"
#include "validparceljpeg.h"
#include "controllermanager.h"

namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = 0);
    ~VideoWidget();

    void camOperationMode();
    void camTestMode();

    void ofOnListLog(bool pFlag);
    void helpList(QString pString);

    void camZoomNorma();
    void camZoomX2();
    void camZoomX4();
    void picture_640x480();
    void picture_800x600();
    void picture_1024x768();
    void picture_1280x1024();
    void picture_1920x1080();

    void inversia(bool pInversia);
    bool f_on_640x480;

private:
    Ui::VideoWidget *ui;

    validParcelJPEG *validJPEG;
    Client_Tcp *clientTcp;
    Udp_Server *udpServer;

    QImage pixmapPicture;
    QImage mZeroImage;

    bool flagMode,flagInversia;

protected:

public slots:
    void logText(QString pString);

private slots:
    void jpegFrame(QByteArray jF);
    void drawPicture();

signals:
    void newLogMsg(QString pString);
    void newVideo(QImage pImage);
    void newCameraInversia(bool pFlag, QString pString);

};

#endif // VIDEOWIDGET_H
