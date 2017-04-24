#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include <QSettings>
#include <QTextCodec>
#include "appcore.h"

AppCore::AppCore(QObject *parent) : QObject(parent)
{
    this->dataLocation = QStandardPaths::standardLocations(QStandardPaths::DataLocation)[0];

    QDir dataDir(this->dataLocation);

    if (!dataDir.exists()) {
        dataDir.mkdir(this->dataLocation);
    }

    QMap<QString, QString> files;
    files["db.sqlite"] = this->dataLocation;

    this->copyFiles(files);

    QSettings settings(":/config.ini", QSettings::IniFormat);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    settings.setIniCodec(codec);
    settings.beginGroup("expense_categories");
    const QStringList childKeys = settings.childKeys();
    QStringList values;
    foreach (const QString &childKey, childKeys)
    values << settings.value(childKey).toString();
    settings.endGroup();

    qDebug() << values;
}

void AppCore::copyFiles(QMap<QString, QString> files) {
    QString filename = "";
    QString distFolder = "";
    QMap<QString, QString>::const_iterator i = files.constBegin();

    while (i != files.constEnd()) {
        filename = i.key();
        distFolder = i.value();
        QFileInfo dataDirInfo(distFolder);

        if (!dataDirInfo.isWritable()) {
            qDebug() << "Have not premissions to write to " + distFolder;
            return;
        }
        QString filePath = distFolder + "/" + filename;
        QFileInfo fileInfo(filePath);

        if (!fileInfo.exists()) {
            QFile::copy(":/" + filename, filePath);
            QFile::setPermissions(filePath, QFileDevice::ReadOwner | QFileDevice::WriteOwner);
        }

        ++i;
    }
}
