#ifndef EXCHANGE_RATE_H
#define EXCHANGE_RATE_H

#include "base_entity.h"
#include "currency.h"

class ExchangeRate : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(Currency* base READ getBase WRITE setBase NOTIFY propChanged)
    Q_PROPERTY(Currency* compare READ getCompare WRITE setCompare NOTIFY propChanged)
    Q_PROPERTY(float rate READ getRate WRITE setRate NOTIFY propChanged)
    Q_PROPERTY(QDateTime date READ getDate WRITE setDate NOTIFY propChanged)

protected:
    Currency * _base;
    Currency * _compare;
    float _rate;
    QDateTime _date;
public:
    ExchangeRate(QObject * parent = 0);
    Currency * getBase();
    Currency * getCompare();
    float getRate();
    QDateTime getDate();
    void setBase(Currency * base);
    void setCompare(Currency * compare);
    void setRate(float rate);
    void setDate(QDateTime date);

signals:
    void propChanged();
};

#endif // EXCHANGE_RATE_H
