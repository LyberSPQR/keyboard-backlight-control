#include "mainwindow.h"
#include <QFile>
#include <iostream>
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    using namespace std;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    // cout << "GOOOOL";
    // QFile file("/sys/devices/platform/tuxedo_keyboard/leds/rgb:kbd_backlight/brightness.txt");
    // QFile file("/home/lyber_spqr/C++/filus.txt");
    // if(file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    // {
    //     QMessageBox msgBox;
    //     msgBox.setText("Простое сообщение!");
    //     msgBox.exec();
    //     QString text_file = "0";
    //     QString text_filus;
    //     QTextStream ReadStream (&file);
    //     text_filus += ReadStream.readAll();
    //     qDebug() << text_filus;

    //     QTextStream WriteStream (&file);
    //     WriteStream << text_file;


    //     file.close();
    // }





    return a.exec();
}
