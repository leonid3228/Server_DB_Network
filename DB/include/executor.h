#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "databaseconnection.h"
#include "QSqlQuery"
#include "QVariantList"

class Executor
{
public:
    Executor();
    Q_DISABLE_COPY(Executor)
    QSqlQuery execute(const QString &queryText, const QVariantList& args = {});

private:
    DataBaseConnection& m_connectionManager;

};

#endif // EXECUTOR_H
