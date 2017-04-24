#include "account.h"

Account::Account()
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
