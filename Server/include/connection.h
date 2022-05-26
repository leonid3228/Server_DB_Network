#ifndef CONNECTION_H
#define CONNECTION_H
#include<QObject>
#include<QTcpSocket>
#include<QVariantList>
#include"type.h"
#include"package.h"
#include<QTcpServer>
#include<worker.h>
class Connection:public QObject
{
public:
    Q_OBJECT
public:
    Connection();

private:
    QTcpServer m_server;
    Worker dbClass;
    QVector<QTcpSocket*> m_clients;
    void connectSocketSignals(QTcpSocket* socket);
private slots:
    void newConnection();
    void clientDisconnected();
    void dataArrived();

private:
    void handlePackage(Package& package, QTcpSocket* socket);
};


#endif // CONNECTION_H
