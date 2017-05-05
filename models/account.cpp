#include "account.h"

QString Account::getIcon() const
{
    return _icon;
}

void Account::setIcon(const QString &icon)
{
    _icon = icon;
}

Account::Account(QObject * parent)
    : BaseEntity(parent)
{

}

QString Account::getName() {
    return this->_name;
}

float Account::getAmount() {
    return this->_amount;
}

User * Account::getOwner() {
    return this->_owner;
}

Currency * Account::getCurrency() {
    return this->_currency;
}

Instance * Account::getInstance()
{
    return this->_instance;
}

void Account::setName(QString name) {
    this->_name = name;
}

void Account::setAmount(float amount) {
    this->_amount = amount;
}

void Account::setOwner(User * owner) {
    this->_owner = owner;
}

void Account::setCurrency(Currency *currency) {
    this->_currency = currency;
}

void Account::setInstance(Instance *instance)
{
    this->_instance = instance;
}

void Account::createFromList(
        Instance *instance,
        User *user,
        Currency * currency,
        QList<Account *> accountList,
        float amount
    )
{
    qDebug() << "Account::createFromList -";

    int timestamp = Account::timestamp();
    QString sql = "insert into account (id, owner_id, instance_id, currency_id, name, icon, amount, created_at, updated_at) values";

    QString ts = QString::number(timestamp);
    QStringList rows;

    foreach(Account *account, accountList) {
        rows.append(QString("('%1','%2','%3',%4,'%5','%6',%7,%8,%9)").arg(
                        Account::genUuid(),
                        user->getId(),
                        instance->getId(),
                        QString::number(currency->getNumber()),
                        account->getName(),
                        account->getIcon(),
                        QString::number(amount), ts, ts)
                    );
    }
    sql += rows.join(", ");

    qDebug() << sql;

    QSqlQuery query;

    if (!query.exec(sql)) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return;
    }
}

QList<Account *> Account::getByInstanceId(uuid instanceId)
{
    qDebug() << "Account::getByInstanceId -" << instanceId;

    QList<Account *> accountList;
    QString sql = "select * from account where instance_id=:instance_id";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":instance_id", QString(instanceId));

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return accountList;
    }

    Instance * instance = Instance::getById(instanceId);

    while (query.next()) {
        Account * account = new Account();
        account->setId(query.value(0).toByteArray());
        account->setOwner(User::getById(query.value(1).toByteArray()));
        account->setInstance(instance);
        account->setCurrency(Currency::getByNumber(query.value(2).toInt()));
        account->setName(query.value(4).toString());
        account->setAmount(query.value(5).toFloat());
        account->setCreatedAt(query.value(6).toDateTime());
        account->setUpdatedAt(query.value(7).toDateTime());

        accountList.append(account);
    }

    return accountList;
}

QList<Account *> Account::getSystem()
{
    qDebug() << "Account::getSystem -";

    QList<Account *> accountList;
    QString sql = "select * from account where system=1";

    QSqlQuery query;

    if (!query.exec(sql)) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return accountList;
    }

    while (query.next()) {
        Account * account = new Account();
        account->setName(query.value(4).toString());
        account->setIcon(query.value(7).toString());

        accountList.append(account);
    }

    return accountList;
}
