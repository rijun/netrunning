#include "backend.h"

#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Backend backend = Backend();

    return a.exec();
}
