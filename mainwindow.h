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
    int updateTimer;
    void update();
    
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MAINWINDOW_H
