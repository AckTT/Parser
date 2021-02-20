#include <QCoreApplication>
#include "parseapp.h"

int main(int argc, char *argv[])
{
    PARSE::ParseApp a(argc, argv);



    return a.exec();
}
