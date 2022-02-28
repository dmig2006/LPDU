#include "client_tcp.h"

Client_Tcp::Client_Tcp(QThread *parent) : QThread(parent)
{

}

Client_Tcp::~Client_Tcp()
{
    tcpSocket -> close();
    tcpSocket -> disconnectFromHost();
    delete tcpSocket;
}

void Client_Tcp::run()
{

}

void Client_Tcp::sendTcpCmd(QString cmd)
{
    tcpSocket = new QTcpSocket;
    tcpSocket -> connectToHost(QHostAddress("10.0.0.250"),80,QIODevice::ReadWrite);

    if(tcpSocket->waitForConnected(100))
    {
//        emit newLogMsg("Связь установлена");

        QByteArray cmd_ba;
        if (tcpSocket->isOpen())
        {
//            emit newLogMsg ("СОЕДИНЕНИЕ УСТАНОВЛЕНО");
            cmd_ba.append(cmd);
            tcpSocket->write(cmd_ba);
            if (tcpSocket->waitForReadyRead()) emit newLogMsg (tcpSocket -> readAll());
        }
        else
        {

        }
        tcpSocket->close();
        tcpSocket->disconnectFromHost();
        tcpSocket->deleteLater();
    }
    else emit newLogMsg ("НЕТ СВЯЗИ");
}

