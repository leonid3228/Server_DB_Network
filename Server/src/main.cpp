#include <QCoreApplication>
#include <QDebug>
#include <worker.h>
#include <connection.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Connection connect;
    return a.exec();
}
