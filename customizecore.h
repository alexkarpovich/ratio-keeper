#ifndef CUSTOMIZECORE_H
#define CUSTOMIZECORE_H

#include <QObject>
#include <QString>
#include <QStringList>
#include "appconfig.h"
#include "models/currency.h"

/**
 * @brief The CustomizeCore class
 *
 * Provides functionality for customization state
 */
class CustomizeCore : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ getUsername WRITE setUsername NOTIFY propChanged)
    Q_PROPERTY(QString email READ getEmail WRITE setEmail NOTIFY propChanged)
    Q_PROPERTY(QString firstName READ getFirstName WRITE setFirstName NOTIFY propChanged)
    Q_PROPERTY(QString lastName READ getLastName WRITE setLastName NOTIFY propChanged)
    Q_PROPERTY(Currency* currency READ getCurrency WRITE setCurrency NOTIFY propChanged)

    AppConfig *config;
    QString _username;
    QString _email;
    QString _firstName;
    QString _lastName;
    Currency * _currency;
    QStringList _categoryList;
    QStringList _accountList;

public:
    explicit CustomizeCore(QObject *parent = 0);

    QString getUsername() const;
    void setUsername(const QString &value);

    QString getEmail() const;
    void setEmail(const QString &value);

    QString getFirstName() const;
    void setFirstName(const QString &value);

    QString getLastName() const;
    void setLastName(const QString &value);

    Currency *getCurrency() const;
    void setCurrency(Currency *value);

    void setCategoryList(const QStringList &value);
    void setAccountList(const QStringList &value);

    AppConfig *getConfig() const;
    void setConfig(AppConfig *value);

signals:
    void propChanged();
public slots:
    QStringList getCategoryList() const;
    QStringList getAccountList() const;
    QList<QObject *> getCurrencyList();
    void addCategory(const QString &value);
};

#endif // CUSTOMIZECORE_H
