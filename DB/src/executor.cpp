#include "executor.h"
#include "QDebug"
Executor::Executor(): m_connectionManager{DataBaseConnection::instance()}
{

}

QSqlQuery Executor::execute(const QString &queryText, const QVariantList &args)
{
    QSqlQuery query {queryText};

    for(int i = 0; i < args.size(); ++i)
    {
        query.bindValue(i, args[i]);
    }
    query.exec();
    return query;
}
