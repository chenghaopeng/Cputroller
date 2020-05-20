#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include <QDir>
#include <QDebug>

const QString speedMethod = "/pwm1_enable";
const QString manualSpeed = "/pwm1";
const QString currentSpeed = "/fan1_input";
const QString temperature = "/temp1_input";

QString findCPUDir() {
    QString prefix = "/sys/class/hwmon";
    QDir dirs(prefix);
    dirs.setFilter(QDir::Dirs);
    foreach(QFileInfo dir, dirs.entryInfoList()) {
        if (dir.fileName() == "." || dir.fileName() == "..") continue;
        QString fullDir = dir.absoluteFilePath();
        if (Utils::isFileExist(fullDir + speedMethod) && Utils::isFileExist(fullDir + manualSpeed) && Utils::isFileExist(fullDir + currentSpeed) && Utils::isFileExist(fullDir + temperature)) {
            return fullDir;
        }
    }
    return "";
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet(Utils::readFile(":/static/default.qss"));
    cpuDir = findCPUDir();
    updateTimer = startTimer(500);
}

void MainWindow::timerEvent(QTimerEvent *event) {
    if (event->timerId() == updateTimer) {
        update();
    }
}

void MainWindow::update() {
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
