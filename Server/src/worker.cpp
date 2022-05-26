#include "worker.h"
#include "QDebug"
Worker::Worker(){}

bool Worker::checkLogin(QVariantList data)
{
    QString tableName{"LogPass"};
    bool resultRequest = dataBase.checkPass(tableName,data.at(0).toString(),data.at(1).toString());
    qDebug()<<resultRequest;
    return resultRequest;
}

void Worker::getRegister(const QString &login, const QString &password,
                         const QString & name, const QString & surName, const QString & info)
{
    QString tableName{"LogPass"};
    QVariantList listToLogandPass;listToLogandPass.push_back(login);listToLogandPass.push_back(password);
    dataBase.insertData(tableName,listToLogandPass);   
}

QVariantList Worker::getDataFromDB(QString login)

{
    QString tableName{"Data"};
    QVariantList dataList = dataBase.getData(tableName,login);
    return dataList;
}





