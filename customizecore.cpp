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

Currency *CustomizeCore::getCurrency() const
{
    return _currency;
}

void CustomizeCore::setCurrency(Currency *value)
{
    _currency = value;
}

QList<ExpenseCategory *> CustomizeCore::getCategoryList() const
{
    return _categoryList;
}

void CustomizeCore::setCategoryList(const QList<ExpenseCategory *> &value)
{
    _categoryList = value;
}

QList<Account *> CustomizeCore::getAccountList() const
{
    return _accountList;
}

void CustomizeCore::setAccountList(const QList<Account *> &value)
{
    _accountList = value;
}

QList<QObject *> CustomizeCore::getCategories()
{
    qDebug() << "CustomizeCore::getCategories -";

    return AppUtility::getObjectList<ExpenseCategory *>(this->getCategoryList());
}

QList<QObject *> CustomizeCore::getAccouns()
{
    qDebug() << "CustomizeCore::getAccouns -";

    return AppUtility::getObjectList<Account *>(this->getAccountList());
}

QList<QObject *> CustomizeCore::getCurrencyList()
{
    qDebug() << "CustomizeCore::getCurrencyList -";

    return AppUtility::getObjectList<ExpenseCategory *>(this->getCategoryList());
}

void CustomizeCore::addCategory(const QString &name, const QString &icon) {
    ExpenseCategory * ctg = new ExpenseCategory();
    ctg->setName(name);
    ctg->setIcon(icon);

    _categoryList.append(ctg);
}
