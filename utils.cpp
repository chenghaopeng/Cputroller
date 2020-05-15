#include "utils.h"

#include <QProcess>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>

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

QString writeSystemFile(const QString &filePath, const QString &text) {
    return Utils::sudo("tee", QStringList() << filePath, text.toUtf8());
}
