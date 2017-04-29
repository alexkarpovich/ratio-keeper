#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "base_entity.h"
#include "currency.h"
#include "user.h"

class Account : public BaseEntity
{
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(float amount READ amount WRITE setAmount)
    Q_PROPERTY(Currency* currency READ getCurrency WRITE setCurrency)
    Q_PROPERTY(User* owner READ getOwner WRITE setOwner)

protected:
    Currency * _currency;
    User * _owner;
    QString _name;
    float _amount;
public:
    Account();
    QString getName();
    float getAmount();
    User * getOwner();
    Currency * getCurrency();
    void setName(QString name);
    void setAmount(float amount);
    void setOwner(User * owner);
    void setCurrency(Currency * currency);
};

#endif // ACCOUNT_H
