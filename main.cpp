#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    MainWindow w;
    QDesktopWidget *desktop = QApplication::desktop();
    w.move((desktop->width() - w.width()) / 2, (desktop->height() - w.height()) / 2);
    w.show();
    
    return a.exec();
}
