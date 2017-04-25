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

    config = new QSettings(":/config.ini", QSettings::IniFormat);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    config->setIniCodec(codec);
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

AppCore::State AppCore::getState() {
    qDebug() << "AppCore::getState" + this->appState;
    return this->appState;
}

void AppCore::setState(State state) {
    qDebug() << "AppCore::setState " + state;
    if (this->appState != state) {
        this->appState = state;
        emit stateChanged(this->appState);

        qDebug() << "AppCore::stateChanged " + this->appState;
    }
}

QStringList AppCore::getDefaultCategories() {
    qDebug() << "AppCore::getDefaultCategories:";
    this->config->beginGroup("expense_categories");

    QStringList categoryKeys = this->config->childKeys();
    QStringList categoryNames;

    foreach (const QString &childKey, categoryKeys) {
        categoryNames.append(this->config->value(childKey).toString());
    }

    this->config->endGroup();

    qDebug() << "AppCore::getDefaultCategories " << categoryNames;

    return categoryNames;
}
