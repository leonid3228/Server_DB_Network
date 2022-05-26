#include "selector.h"
#include "QSqlRecord"
#include "QDebug"
void Selector::selectAll(const QString & tableName,QVector<QVariantList>& returnData,const QString &login,const QString & password)
{


    QString query;
    query  = ("SELECT  * FROM Contacts WHERE Login = "+login);

    QSqlQuery resultQuery;
    resultQuery = m_executor.execute(query);

    while (resultQuery.next())
    {
        const QSqlRecord& resultRecord = resultQuery.record();
        QVariantList result;
        for (int i = 0; i < resultRecord.count(); ++i)
        {
            result.push_back(resultRecord.value(i));
        }
        returnData.push_back(result);
    }

 }

 bool Selector::checkLogin(const QString &tableName, const QString &login, const QString &password)
 {
    // QString dbLog,dbPass;
     QString query{"SELECT  * FROM " + tableName+" WHERE Login = "+login+" AND Password = " +password};
     QSqlQuery resultQuery;
      resultQuery = m_executor.execute(query);

      resultQuery.next();
          const QSqlRecord& resultRecord = resultQuery.record();

           if((resultRecord.value(0).toString()==login)&&(resultRecord.value(1).toString()==password))
               return true;
           else
               return false;

 }

 QVariantList Selector::getData(const QString &tableName, const QString &login)
 {
     QString query{"SELECT  * FROM " + tableName+" WHERE Login = "+login};
     QSqlQuery resultQuery;
     resultQuery = m_executor.execute(query);
     QVariantList result;

     while (resultQuery.next())
     {
         const QSqlRecord& resultRecord = resultQuery.record();
         for (int i = 0; i < resultRecord.count(); ++i)
         {
             qDebug()<<resultRecord.value(i).toString();
             result.push_back(resultRecord.value(i));
         }
     }
     return result;
 }

