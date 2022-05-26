#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <memory>
class privateData;
class DataBaseConnection
{
public:
    DataBaseConnection(const DataBaseConnection&)=delete;

    DataBaseConnection& operator= (const DataBaseConnection&)=delete;

    static DataBaseConnection &instance();
    ~DataBaseConnection();
private:
    class privateData;
    std::unique_ptr<privateData> m_d;

    DataBaseConnection();

};

#endif // DATABASECONNECTION_H
