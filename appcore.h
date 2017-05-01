#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QMap>
#include <QDebug>
#include "appconfig.h"
#include "customizecore.h"
#include "models/account.h"
#include "models/user.h"
#include "models/instance.h"
#include "models/expense_category.h"


/**
 * @brief The AppCore class
 * The class is intermediate layer between QML and C++ functionality
 */
class AppCore : public QObject
{
    Q_OBJECT
    Q_ENUMS(State)
    Q_PROPERTY(State state READ getState WRITE setState NOTIFY stateChanged)

public:
    AppCore(QObject *parent = 0);
    enum State {
        START=0,
        CUSTOMIZE,
        DASHBOARD,
        CATEGORY_ADD,
        CURRENCY_LIST
    };

    State getState();
    Instance * getInstance();
    User * getUser();
    void setInstance(Instance * instance);
    void setUser(User * user);

    Currency *getCurrency() const;
    void setCurrency(Currency *currency);

    CustomizeCore *getCustomizeCore() const;
    void setCustomizeCore(CustomizeCore *value);

protected:
    /** dataLocation - place where sqlite file put to */
    QString dataLocation;

    /** sdb - QSqlDatabase app instance */
    QSqlDatabase sdb;

    /** config - it's init from config.ini */
    AppConfig *config = NULL;

    /** appState - stores what pare is displayed */
    State appState;

    /** customizeCore - core to handle customize state */
    CustomizeCore *customizeCore;

    /** instance - actual app instance */
    Instance *instance = NULL;

    /** user - actual user */
    User *user = NULL;

    /** currency - actual currency */
    Currency *currency = NULL;

private:
    void copyFiles(QMap<QString, QString> files);
    void initDataBase();
    void initActuals();

signals:
    void stateChanged(State state);

public slots:

    /** Returns actual list of categories */
    QList<QObject*> getCategoryList();

    /**
     * @brief getAccountList
     * @return list of actual accounts for current instance
     */
    QList<QObject *> getAccountList();

    /**
     * @brief getCurrencyList
     * @return all currencies
     */
    QList<QObject *> getCurrencyList();

    /** Changes app state */
    void setState(State state);

    /** Configure app using customizeCore data */
    void configureInstance();

    /**
     * @brief isLoggedIn
     * @return true if user is set
     */
    bool isLoggedIn();
};

#endif // APPCORE_H
