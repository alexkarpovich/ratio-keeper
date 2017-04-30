#include "exchange_rate.h"

ExchangeRate::ExchangeRate(QObject *parent)
    : BaseEntity(parent)
{

}

Currency * ExchangeRate::getBase() {
    return this->_base;
}

Currency * ExchangeRate::getCompare() {
    return this->_compare;
}

float ExchangeRate::getRate() {
    return this->_rate;
}

QDateTime ExchangeRate::getDate() {
    return this->_date;
}

void ExchangeRate::setBase(Currency * base) {
    this->_base = base;
}

void ExchangeRate::setCompare(Currency * compare) {
    this->_compare = compare;
}

void ExchangeRate::setRate(float rate) {
    this->_rate = rate;
}

void ExchangeRate::setDate(QDateTime date) {
    this->_date = date;
}
