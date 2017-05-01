#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "base_entity.h"
#include "instance.h"
#include "currency.h"
#include "user.h"

class Account : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY propChanged)
    Q_PROPERTY(float amount READ getAmount WRITE setAmount NOTIFY propChanged)
    Q_PROPERTY(Currency* currency READ getCurrency WRITE setCurrency NOTIFY propChanged)
    Q_PROPERTY(User* owner READ getOwner WRITE setOwner NOTIFY propChanged)
    Q_PROPERTY(Instance* instance READ getInstance WRITE setInstance NOTIFY propChanged)

protected:
    Currency * _currency;
    User * _owner;
    Instance * _instance;
    QString _name;
    float _amount;
public:
    Account(QObject * parent = 0);
    QString getName();
    float getAmount();
    User * getOwner();
    Currency * getCurrency();
    Instance *getInstance();
    void setName(QString name);
    void setAmount(float amount);
    void setOwner(User * owner);
    void setCurrency(Currency * currency);
    void setInstance(Instance * instance);

    static void createFromList(Instance * instance, User * user, Currency * currency, QStringList names, float amount = 0);
    static QList<Account *> getByInstanceId(uuid instanceId);

signals:
    void propChanged();
};

#endif // ACCOUNT_H
