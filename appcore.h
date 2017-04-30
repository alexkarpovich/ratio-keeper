#ifndef APPCORE_H
#define APPCORE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QSqlDatabase>
#include <QMap>
#include <QDebug>
#include "appconfig.h"
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
    explicit AppCore(QObject *parent = 0);
    enum State {
        START=0,
        CUSTOMIZE,
        DASHBOARD,
        CATEGORY_ADD,
    };

    State getState();
    Instance * getInstance();
    User * getUser();
    void setInstance(Instance * instance);
    void setUser(User * user);

    Currency *getCurrency() const;
    void setCurrency(Currency *currency);

protected:
    /** dataLocation - place where sqlite file put to */
    QString dataLocation;

    /** sdb - QSqlDatabase app instance */
    QSqlDatabase sdb;

    /** config - it's init from config.ini */
    AppConfig * config = NULL;

    /** appState - stores what pare is displayed */
    State appState;

    /** instance - actual app instance */
    Instance * instance = NULL;

    /** user - actual user */
    User * user = NULL;

    /** currency - actual currency */
    Currency * currency = NULL;

    /** customCategories - list of default categories + custom on customization state */
    QStringList customCategories;


private:
    void copyFiles(QMap<QString, QString> files);
    void initDataBase();
    void initActuals();

signals:
    void stateChanged(State state);

public slots:
    /** Returns list of default categories stored in config.ini */
    QStringList getDefaultCategories();

    /**
     * @brief getDefaultAccounts
     * @return list of default accounts stored in config.ini
     */
    QStringList getDefaultAccounts();

    /**
     * @brief getCustomCategories
     * @return customCategories
     */
    QStringList getCustomCategories();

    /** Returns actual list of categories */
    QList<QObject*> getCategoryList();

    /**
     * @brief getAccountList
     * @return list of actual accounts for current instance
     */
    QList<QObject *> getAccountList();

    /** Checks if actual user is set */
    bool hasActiveUser();

    /** Changes app state */
    void setState(State state);

    /** Configure app with custom categories */
    void configureInstance(QList<QString> selected);

    /**
     * @brief addCustomCategory
     * @param category
     */
    void addCustomCategory(QString category);


};

#endif // APPCORE_H
