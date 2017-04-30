#ifndef APPCONFIG_H
#define APPCONFIG_H

#include <QDebug>
#include <QString>
#include <QSettings>
#include <QTextCodec>

class AppConfig
{
protected:
    QSettings * config;
public:
    AppConfig();

    QStringList get(QString group);
    QString get(QString group, QString item);
};

#endif // APPCONFIG_H
