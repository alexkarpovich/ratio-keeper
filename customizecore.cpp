#include "customizecore.h"

CustomizeCore::CustomizeCore(QObject *parent) : QObject(parent)
{
    config = new AppConfig();
    _currency = Currency::getByNumber(config->get("currency", "default").toInt());
    _user = new User();
    _user->setUsername(config->get("user", "username"));
    _user->setActive(true);
    _accountList = Account::getSystem();
    _categoryList = ExpenseCategory::getSystem();
}

User *CustomizeCore::getUser() const
{
    return _user;
}

void CustomizeCore::setUser(User *user)
{
    _user = user;
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

QList<QObject *> CustomizeCore::getCategoryList() const
{
    return _categoryList;
}

void CustomizeCore::setCategoryList(const QList<QObject *> &value)
{
    _categoryList = value;
}

QList<QObject *> CustomizeCore::getAccountList() const
{
    return _accountList;
}

void CustomizeCore::setAccountList(const QList<QObject *> &value)
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

void CustomizeCore::addCategory(const QString &name, const QString &icon) {
    ExpenseCategory * ctg = new ExpenseCategory();
    ctg->setName(name);
    ctg->setIcon(icon);

    _categoryList.append(ctg);
}
