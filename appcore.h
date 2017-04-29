#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QSettings>
#include <QSqlDatabase>
#include <QMap>
#include <QDebug>
#include "models/user.h"
#include "models/instance.h"
#include "models/expense_category.h"

class AppCore : public QObject
{
    Q_OBJECT
    Q_ENUMS(State)
    Q_PROPERTY(State state READ getState WRITE setState NOTIFY stateChanged)

public:
    explicit AppCore(QObject *parent = 0);
    enum State {
        START=0,
        CUSTOMIZE,
        DASHBOARD
    };

    State getState();

public slots:
    QStringList getDefaultCategories();
    void setState(State state);
    void configureInstance(QList<QString> selected);

protected:
    QString dataLocation;
    QSqlDatabase sdb;
    QSettings * config;
    State appState;

private:
    void copyFiles(QMap<QString, QString> files);
    void initDataBase();

signals:
    void stateChanged(State state);


};

#endif // APPCORE_H
