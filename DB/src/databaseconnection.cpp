#include "databaseconnection.h"
#include "QString"
#include "QSqlDatabase"
#include "QStandardPaths"
#include "QSqlQuery"
#include "QDebug"
class Closer{
public:
    void operator()(QSqlDatabase* db){

        db->close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        delete db;
        qDebug()<<"DB Close";
    }

};

class DataBaseConnection::privateData
{
public:
    std::unique_ptr<QSqlDatabase,Closer> m_database;
    QString m_dbPath;
    void setUp();
    void setUpWorkspace();
    void setupTables();
};

void DataBaseConnection::privateData::setUp()
{
    QString driver("QSQLITE");
    setUpWorkspace();
    auto *db = new QSqlDatabase(QSqlDatabase::addDatabase(driver));
    m_database.reset(db);
    m_database->setDatabaseName("LenDB");
    m_database->open();
    setupTables();
}

void DataBaseConnection::privateData::setUpWorkspace()
{
    const QString databaseName {"ContactsDB"};

    const QString location {QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)};
    const QString fullPath {location + "/" + databaseName};

    m_dbPath = fullPath;
}

void DataBaseConnection::privateData::setupTables()
{
    QVector<QSqlQuery> creationQueries= {
        QSqlQuery {
            "CREATE TABLE IF NOT EXISTS LogPass"
            "("
            "Login TEXT NOT NULL,"
            "Password TEXT NOT NULL"
            ")"
        }
    };
    for (auto& query : creationQueries)
    {
        query.exec();
    }
    QVector<QSqlQuery> creationQueriesData= {
        QSqlQuery {

            "CREATE TABLE IF NOT EXISTS Data"
            "("
            "Login TEXT NOT NULL,"
            "Name TEXT NOT NULL,"
            "Surname TEXT NOT NULL,"
            "Info TEXT NOT NULL"
            ")"
        }
    };
    for (auto& query : creationQueriesData)
    {
        query.exec();

    }
    qDebug() << "Open DB";
}

DataBaseConnection& DataBaseConnection::instance()
{
    static DataBaseConnection instance{};
    return instance;
}

DataBaseConnection::DataBaseConnection():m_d{new privateData}

{
    m_d->setUp();
}

DataBaseConnection::~DataBaseConnection()
{}


