#include "manipulator.h"
#include "QVector"
#include "QDebug"
#include "mapper.h"
Manipulator::Manipulator(){}

void Manipulator::insert(const QString & tableName, const QVariantList & data)
{
    QString query {generateQuery(tableName, data.size())};
    m_executor.execute(query, data);
}


QString Manipulator::binding( int paramCount){
    QString bindValue;
    QVector<QString> str;
    for (int i = 0;i<=paramCount;++i){
        str.push_back("?");
        str.push_back(",");
    }
    str.pop_back();
    for (int i = 0;i<(paramCount*2-1);++i){
        bindValue +=str.at(i);
    }
    return bindValue;
}

QString Manipulator::generateQuery(const QString& tableName, size_t paramCount)
{
    QString query = "INSERT INTO " + tableName +  "("+tablesMapping.at(tableName)+")"
                        " VALUES (";
    query += binding(paramCount);
    query += ")";
    return query;
}
