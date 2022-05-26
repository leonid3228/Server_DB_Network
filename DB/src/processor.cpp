#include "processor.h"
#include "QDebug"
#include "manipulator.h"
#include "selector.h"
struct Processor::ProcessorPrivate
{
    Manipulator manipulator;
    Selector selector;
};

Processor::Processor():m_proccesor (new ProcessorPrivate ){}
Processor::~Processor(){}

void Processor::insertData(const QString & tableName, const QVariantList & dataInsert)
{
    m_proccesor->manipulator.insert(tableName,dataInsert);
}

bool Processor::checkPass(const QString& tableName, const QString &login,const QString & password)
{
    return m_proccesor->selector.checkLogin(tableName,login,password);
}

QVariantList Processor::getData(const QString &tableName, const QString &login)
{
    return m_proccesor->selector.getData(tableName,login);
}
