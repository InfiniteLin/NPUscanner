#include "mainwindow.h"
#include "myWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //QApplication app(argc, argv);
    //MyWindow window;
    //window.show();

    return a.exec();
}
