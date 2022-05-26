#include "connection.h"
#include <algorithm>
#include <QVector>
Connection::Connection()
{
    m_server.listen(QHostAddress::Any,5555);

    connect(&m_server, &QTcpServer::newConnection,
            this, &Connection::newConnection);
}

void Connection::newConnection()
{
    qDebug() << "New Client";
    QTcpSocket* clientConnection = m_server.nextPendingConnection();
    if (clientConnection)
    {
        connectSocketSignals(clientConnection);
        m_clients.push_back(clientConnection);
    }
}

void Connection::dataArrived()
{ 
    QObject *senderOBJ = sender();
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(senderOBJ);
    QDataStream in {socket};
    Package package;
    in>>package;
    handlePackage(package,socket);
}

void Connection::handlePackage(Package &package, QTcpSocket *socket)
{

    switch (package.pckg()) {

    case PckgType::REQUEST_LOGIN:{

        bool check = dbClass.checkLogin(package.data());
        QVariantList data;
        data.push_back(check);
        Package packageRequest(data,PckgType::REQUEST_LOGIN);
        socket->write(packageRequest.rawData());
        if(check == true){
            QString log = package.data().at(0).toString();
            QVariantList data = dbClass.getDataFromDB(log);
            Package packageRequest(data,PckgType::REQUEST_DATA);
            socket->write(packageRequest.rawData());
        }
        break;}
    case PckgType::REQUEST_REGISTER:{

        QString log = package.data().at(0).toString();
        QString pass = package.data().at(1).toString();
        QString name = package.data().at(2).toString();
        QString surName = package.data().at(3).toString();
        QString info = package.data().at(4).toString();

        dbClass.getRegister(log,pass,name,surName,info);
        bool ok = true;
        QVariantList data;data.push_back(ok);
        Package packageRequest(data,PckgType::REQUEST_REGISTER_OK);
        socket->write(packageRequest.rawData());
        break;
    }
    }
}

void Connection::clientDisconnected()
{
    QObject * senderOBJ = sender();
    QTcpSocket * socket = qobject_cast<QTcpSocket *>(senderOBJ);

    m_clients.erase(std::remove(m_clients.begin(),m_clients.end(),socket),m_clients.end());

    socket->deleteLater();
    qDebug() << "Client disconnected!";
}

void Connection::connectSocketSignals(QTcpSocket *socket)
{
    connect(socket, &QAbstractSocket::disconnected,
            this, &Connection::clientDisconnected);

    connect(socket, &QAbstractSocket::readyRead,
            this, &Connection::dataArrived);
}
