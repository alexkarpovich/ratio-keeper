#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QMap>
#include <QDebug>

class AppCore : public QObject
{
    Q_OBJECT
protected:
    QString dataLocation;

public:
    explicit AppCore(QObject *parent = 0);

private:
    void copyFiles(QMap<QString, QString> files);

};

#endif // APPCORE_H
