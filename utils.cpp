#include "utils.h"

#include <QProcess>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

QString Utils::exec(const QString &cmd, QStringList args, QByteArray data) {
    QProcess *process = new QProcess;
    process->start(cmd, args);
    
    if (!data.isEmpty()) {
        process->write(data);
        process->waitForBytesWritten();
        process->closeWriteChannel();
    }
    
    process->waitForFinished();
    
    QTextStream res(process->readAllStandardOutput());
    
    process->kill();
    process->close();
    
    return res.readAll().trimmed();
}

QString Utils::sudo(const QString &cmd, QStringList args, QByteArray data) {
    args.push_front(cmd);
    return Utils::exec("pkexec", args, data);
}

QString Utils::writeSystemFile(const QString &filePath, const QString &text) {
    return Utils::sudo("tee", QStringList() << filePath, text.toUtf8());
}

QString Utils::readFile(const QString &filePath) {
    QFile file(filePath);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString text = stream.readAll();
    file.close();
    return text;
}

bool Utils::isFileExist(const QString &filePath) {
    QFileInfo fileInfo(filePath);
    return fileInfo.isFile();
}
