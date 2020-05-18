#ifndef UTILS_H
#define UTILS_H

#include <QStringList>

class Utils {
public:
    static QString exec(const QString &cmd, QStringList args = QStringList(), QByteArray data = QByteArray());
    static QString sudo(const QString &cmd, QStringList args = QStringList(), QByteArray data = QByteArray());
    static QString writeSystemFile(const QString &filePath, const QString &text);
    static QString readFile(const QString &filePath);
};

#endif // UTILS_H
