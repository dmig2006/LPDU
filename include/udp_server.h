#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <QThread>
#include <QUdpSocket>

#include "parcels_irzcam.h"

class Udp_Server : public QThread
{
    Q_OBJECT
public:
    explicit Udp_Server(QThread *parent = 0);
    ~Udp_Server();

private:
    QUdpSocket *udpsocket;
    QByteArray udpBufferSend, udpBufferRecive;
     int ii;
     bool flag_connect_udp_port;

protected:
    void run();

signals:
    void sendBuffer (QString);
    void sendParcelJPEG(QByteArray);

public slots:
    void readyReadUdp();
};

#endif // UDP_SERVER_H

