#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyGraphics g;
    g.resize(500,400);
    g.show();
    return a.exec();
}
