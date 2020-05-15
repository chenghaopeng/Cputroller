#ifndef UTILS_H
#define UTILS_H

#include <QStringList>

class Utils {
public:
    static QString exec(const QString &cmd, QStringList args = QStringList(), QByteArray data = QByteArray());
    static QString sudo(const QString &cmd, QStringList args = QStringList(), QByteArray data = QByteArray());
    static QString writeSystemFile(const QString &filePath, const QString &text);
};

#endif // UTILS_H
