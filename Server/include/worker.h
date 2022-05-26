#pragma once
#include<QObject>
#include<QVariantList>
#include"type.h"
#include"package.h"
#include"processor.h"

class Worker:public QObject
{
    Q_OBJECT
public:
    Worker();

    Processor dataBase;
    bool checkLogin(QVariantList data);
    void getRegister(const QString &login, const QString &password,
                     const QString & name, const QString & surName, const QString & info);
    void handlePackage(Package&);
    QVariantList getDataFromDB(QString);
private slots:

};

