#ifndef SELECTOR_H
#define SELECTOR_H
#include "executor.h"
#include "QSqlRecord"
#include "QVector"
#include "QVariantList"
class Selector
{

public:
    void selectAll(const QString & tableName, QVector<QVariantList>& returnData, const QString &login, const QString &password);
bool checkLogin(const QString & tableName,const QString &login, const QString &password);
QVariantList getData(const QString& tableName, const QString& login);
private:
    Executor m_executor;

};

#endif // SELECTOR_H
