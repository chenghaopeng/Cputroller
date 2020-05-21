#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    QString cpuDir;
    int cpuNumber;
    int updateTimer;
    void update();
    void changeStrategy(QString strategy);
    
protected:
    void timerEvent(QTimerEvent *event);
private slots:
    void on_btnFanSpeedAuto_clicked();
    void on_sdrFanSpeed_sliderReleased();
    void on_btnStrategyPerformance_clicked();
    void on_btnStrategyOndemand_clicked();
    void on_btnStrategyPowersave_clicked();
};

#endif // MAINWINDOW_H
