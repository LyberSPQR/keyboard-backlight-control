#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Keyboard-backlight-control");
    setCurBrightness();
    int initial_slider_position = cur_brightness_value / 2.57;
    if(initial_slider_position != 0)
    {
        initial_slider_position +=1;
    }
    ui->horizontalSlider->setValue(initial_slider_position);
    ui->label_4->setText(QString::number(initial_slider_position));
     // writeCurBrightness(100);
    // QFile file("/home/lyber_spqr/C++/filus.txt");

    // if(file.open(QIODevice::ReadWrite /*| QIODevice::Truncate*/))
    // {
    //     QMessageBox msgBox;
    //     msgBox.setText("Простое сообщение!");
    //     msgBox.exec();
    //     QString current_brightness;
    //     this->cur_brightness_value= current_brightness.toInt();
    //     qDebug() << "cur_brightness_value" << cur_brightness_value;
    //     QTextStream ReadStream (&file);
    //     current_brightness += ReadStream.readAll();
    //     qDebug() << current_brightness;
    // }
    //  if(file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    // {
    //     QString text_file = "0";
    //     QTextStream WriteStream (&file);
    //     WriteStream << text_file;
    // }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked() // + button
{
    if(cur_brightness_value + 51 <= 255)
    {

        // QFile file("/home/lyber_spqr/C++/filus.txt");
        QFile file("/sys/devices/platform/tuxedo_keyboard/leds/rgb:kbd_backlight/brightness");
        if(file.open(QIODevice::ReadWrite | QIODevice::Truncate))
        {

            QTextStream WriteStream (&file);
            WriteStream << QString::number(cur_brightness_value);
        }
    }
}
void MainWindow::on_pushButton_clicked() // - button
{
    if(cur_brightness_value - 51 >= 0)
    {
        QFile file("/home/lyber_spqr/C++/filus.txt");
        if(file.open(QIODevice::ReadWrite | QIODevice::Truncate))
        {

            QTextStream WriteStream (&file);
            WriteStream << QString::number(cur_brightness_value);
        }
    }
}
void MainWindow::setCurBrightness()
{
    // QFile file("/home/lyber_spqr/C++/filus.txt");
    QFile file("/sys/devices/platform/tuxedo_keyboard/leds/rgb:kbd_backlight/brightness");

    if(file.open(QIODevice::ReadWrite/*| QIODevice::Truncate*/))
    {
        // QMessageBox msgBox;
        // msgBox.setText("Яркость считана из файла");
        // msgBox.exec();

        QTextStream ReadStream (&file);
        QString current_brightness;
        current_brightness += ReadStream.readAll();
        ui->label_7->setText(current_brightness);

        this->cur_brightness_value = current_brightness.toInt();
        qDebug() << "cur_brightness_value: " << this->cur_brightness_value;
    }
     file.close();
}
void MainWindow::writeCurBrightness(int brightness)
{
    QFile file("/sys/devices/platform/tuxedo_keyboard/leds/rgb:kbd_backlight/brightness");
    if(file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
         brightness  *= 2.57;
        if(brightness <= 255 && brightness >= 0)
        {
             if(brightness != 0)
            {
                brightness += 1;
             }
            QTextStream WriteStream (&file);
            WriteStream << QString::number(brightness);
            file.close();
            setCurBrightness();
              // this->cur_brightness_value = brightness;
        }
        else
        {
            QMessageBox msgBox;
            msgBox.setText("значения для записи внее предела диапазона");
            msgBox.exec();
        }
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Файл недоступен для записи");
        msgBox.exec();
    }
     file.close();
}
void MainWindow::on_horizontalSlider_actionTriggered(int action)
{
    int slider_value = ui->horizontalSlider->sliderPosition();
    if(slider_value != 0)
    ui->label_4->setText(QString::number(slider_value + 1));
    else
        ui->label_4->setText(QString::number(slider_value));
    writeCurBrightness(slider_value);


    ui->label_6->setText(QString::number(this->cur_brightness_value) /*QString::number(bright_value)*/);

}


void MainWindow::on_radioButton_3_clicked() // white
{
    QString color = "255 255 255";
    writeCurBacklightColor(color);
}


void MainWindow::on_radioButton_clicked() // blue
{
    QString color = "0 0 255";
    writeCurBacklightColor(color);
}


void MainWindow::on_radioButton_2_clicked() // green
{
    QString color = "0 255 0";
    writeCurBacklightColor(color);
}


void MainWindow::on_radioButton_7_clicked() // red
{
    QString color = "255 0 0";
    writeCurBacklightColor(color);
}


// void MainWindow::setCurBacklightColor()
// {
//     QFile file("/home/lyber_spqr/C++/filus.txt");

//     if(file.open(QIODevice::ReadWrite/*| QIODevice::Truncate*/))
//     {
//         // QMessageBox msgBox;
//         // msgBox.setText("Яркость считана из файла");
//         // msgBox.exec();

//         QTextStream ReadStream (&file);
//         QString current_brightness;
//         current_brightness += ReadStream.readAll();
//         ui->label_7->setText(current_brightness);

//         this->cur_brightness_value = current_brightness.toInt();
//         qDebug() << "cur_brightness_value: " << this->cur_brightness_value;
//     }
//     file.close();
// }

void MainWindow::writeCurBacklightColor(QString rgb_value)
{
    QFile rgb_file("/sys/devices/platform/tuxedo_keyboard/leds/rgb:kbd_backlight/multi_intensity");
    if(rgb_file.open(QIODevice::ReadWrite | QIODevice::Truncate))
    {
        QTextStream WriteStream (&rgb_file);
        WriteStream << rgb_value;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("Файл rgb недоступен для записи");
        msgBox.exec();
    }
    rgb_file.close();
}
