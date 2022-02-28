#ifndef CLIENT_TCP_H
#define CLIENT_TCP_H

#include <QThread>
#include <QTcpSocket>
#include <QTcpServer>

class Client_Tcp : public QThread
{
    Q_OBJECT

public:
    explicit Client_Tcp(QThread *parent = 0);
    ~Client_Tcp();

private:
    QTcpSocket *tcpSocket;

protected:
    void run();

signals:
    void newLogMsg(QString);

public slots:
    void sendTcpCmd (QString cmd);
};

#endif // CLIENT_TCP_H
