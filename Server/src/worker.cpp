#include "worker.h"
#include "QDebug"
Worker::Worker(){}

bool Worker::checkLogin(QVariantList data)
{
    QString tableName{"LogPass"};
    bool resultRequest = dataBase.checkPass(tableName,data.at(0).toString(),data.at(1).toString());
    return resultRequest;
}

void Worker::getRegister(const QString &login, const QString &password,
                         const QString & name, const QString & surName, const QString & info)
{
    QString tableForLogin{"LogPass"};
    QVariantList listToLogandPass;listToLogandPass.push_back(login);listToLogandPass.push_back(password);
    dataBase.insertData(tableForLogin,listToLogandPass);

    QString tableName{"Data"};
    QVariantList listToData;listToData.push_back(login);listToData.push_back(name);
    listToData.push_back(surName);listToData.push_back(info);
    dataBase.insertData(tableName,listToData);
}

QVariantList Worker::getDataFromDB(QString login)

{
    QString tableName{"Data"};
    QVariantList dataList = dataBase.getData(tableName,login);
    return dataList;
}





