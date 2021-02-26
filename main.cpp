#include <QCoreApplication>
#include "parseapp.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    PARSER::ParseApp a(argc, argv);

    PARSER::MainWindow w;
    w.show();

    return a.exec();
}
