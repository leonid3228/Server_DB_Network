#ifndef PROCESSOR_H
#define PROCESSOR_H
#include <memory>
#include <QVector>
#include <QString>
#include <QVariantList>
class Processor
{
public:
    Processor();
    ~Processor();
    void insertData(const QString &tableName, const QVariantList &dataInsert);
    bool checkPass(const QString& tableName,const QString &login,const QString & password);
    //    bool registerPerson(const QString& tableName,const QString &login,
    //                     const QString & password, const QString & password, const QString & password);
    QVariantList getData(const QString& tableName,const QString &login);
private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_proccesor;
};

#endif // PROCESSOR_H
