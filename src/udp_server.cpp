
#include "udp_server.h"

Udp_Server::Udp_Server(QThread *parent) : QThread(parent)
{
    udpsocket = new QUdpSocket;
    udpsocket -> bind(QHostAddress("10.0.0.204"),44000,QUdpSocket::ShareAddress); //связывание порта с адресом при получении посылки отправляется сигнал readyread();
}

Udp_Server::~Udp_Server()
{
    udpsocket -> disconnectFromHost();
    delete udpsocket;
}

void Udp_Server::run()
{
    connect (udpsocket, SIGNAL(readyRead()),this,SLOT(readyReadUdp()),Qt::DirectConnection);
    exec();
}

void Udp_Server::readyReadUdp()
{
    while (udpsocket -> hasPendingDatagrams())
    {
        QByteArray   buffer;
        QHostAddress sender;
        quint16      senderPort;

        buffer.resize(udpsocket -> pendingDatagramSize());
        udpsocket -> readDatagram(buffer.data(),buffer.size(),&sender, &senderPort);
        emit sendParcelJPEG(buffer);

        //str.append(sender.toString()).append(" : ").append(QString::number(senderPort)).append(" : ").append(QString::number(buffer.size())).append(" ... ");//.append(buffer);
        //emit sendBuffer(str);
       //qDebug() << str;
    }
}
