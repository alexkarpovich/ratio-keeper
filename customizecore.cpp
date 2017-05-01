#include "customizecore.h"

CustomizeCore::CustomizeCore(QObject *parent) : QObject(parent)
{
    config = new AppConfig();
    _currency = Currency::getByNumber(config->get("currency", "default").toInt());
    _accountList = config->get("accounts");
    _categoryList = config->get("expense_categories");
}

AppConfig *CustomizeCore::getConfig() const
{
    return config;
}

void CustomizeCore::setConfig(AppConfig *value)
{
    config = value;
}

QString CustomizeCore::getUsername() const
{
    return _username;
}

void CustomizeCore::setUsername(const QString &value)
{
    _username = value;
}

QString CustomizeCore::getEmail() const
{
    return _email;
}

void CustomizeCore::setEmail(const QString &value)
{
    _email = value;
}

QString CustomizeCore::getFirstName() const
{
    return _firstName;
}

void CustomizeCore::setFirstName(const QString &value)
{
    _firstName = value;
}

QString CustomizeCore::getLastName() const
{
    return _lastName;
}

void CustomizeCore::setLastName(const QString &value)
{
    _lastName = value;
}

Currency *CustomizeCore::getCurrency() const
{
    return _currency;
}

void CustomizeCore::setCurrency(Currency *value)
{
    _currency = value;
}

QStringList CustomizeCore::getCategoryList() const
{
    return _categoryList;
}

void CustomizeCore::setCategoryList(const QStringList &value)
{
    _categoryList = value;
}

QStringList CustomizeCore::getAccountList() const
{
    return _accountList;
}

void CustomizeCore::setAccountList(const QStringList &value)
{
    _accountList = value;
}

QList<QObject *> CustomizeCore::getCurrencyList()
{
    qDebug() << "CustomizeCore::getCurrencyList -";

    QList<Currency *> currencies = Currency::getAll();
    QList<QObject*> currencyList;

    foreach (Currency* cur, currencies) {
        currencyList.append(cur);
    }

    return currencyList;
}

void CustomizeCore::addCategory(const QString &value) {
    _categoryList.append(value);
}
