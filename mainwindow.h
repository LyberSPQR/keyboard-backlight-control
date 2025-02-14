#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void setCurBrightness();

    void writeCurBrightness(int brightness);

    void on_horizontalSlider_actionTriggered(int action);


    void on_radioButton_3_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_7_clicked();

    void writeCurBacklightColor(QString rgb_value);
private:
    int cur_brightness_value;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
