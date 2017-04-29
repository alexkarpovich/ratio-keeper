#ifndef EXCHANGE_RATE_H
#define EXCHANGE_RATE_H

#include "base_entity.h"
#include "currency.h"

class ExchangeRate : public BaseEntity
{
    Q_PROPERTY(Currency* base READ getBase WRITE setBase)
    Q_PROPERTY(Currency* compare READ getCompare WRITE setCompare)
    Q_PROPERTY(float rate READ getRate WRITE setRate)
    Q_PROPERTY(QDateTime date READ getDate WRITE setDate)

protected:
    Currency * _base;
    Currency * _compare;
    float _rate;
    QDateTime _date;
public:
    ExchangeRate();
    Currency * getBase();
    Currency * getCompare();
    float getRate();
    QDateTime getDate();
    void setBase(Currency * base);
    void setCompare(Currency * compare);
    void setRate(float rate);
    void setDate(QDateTime date);
};

#endif // EXCHANGE_RATE_H
