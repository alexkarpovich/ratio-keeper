#include "appconfig.h"

AppConfig::AppConfig()
{
    config = new QSettings(":/config.ini", QSettings::IniFormat);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    config->setIniCodec(codec);
}

QStringList AppConfig::get(QString group)
{
    qDebug() << "AppConfig::get -" << group;
    this->config->beginGroup(group);

    QStringList keys = this->config->childKeys();
    QStringList values;

    foreach (const QString &childKey, keys) {
        values.append(this->config->value(childKey).toString());
    }

    this->config->endGroup();

    qDebug() << "AppConfig::get:" << values;

    return values;
}

QString AppConfig::get(QString group, QString item)
{
    return config->value(QString("%1/%2").arg(group, item)).toString();
}
