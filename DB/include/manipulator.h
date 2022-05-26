#ifndef MANIPULATOR_H
#define MANIPULATOR_H
#include "executor.h"
#include "QSqlQuery"
#include "QVariantList"

class Manipulator
{
public:
    Manipulator();
     Executor m_executor;
    void insert(const QString&, const QVariantList &);
    QString generateQuery(const QString &, size_t );
    QString binding(int paramCount);
};

#endif // MANIPULATOR_H
