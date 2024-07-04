#include "mainwindowserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowserver w;
    w.show();
    return a.exec();
}
