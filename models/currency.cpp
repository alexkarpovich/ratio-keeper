#include "currency.h"

Currency::Currency()
{

}

int Currency::getNumber() {
    return this->_number;
}

QString Currency::getName() {
    return this->_name;
}

QString Currency::getCode() {
    return this->_code;
}

int Currency::getMinorUnits() {
    return this->_minorUnits;
}

void Currency::setNumber(int number) {
    this->_number = number;
}
void Currency::setName(QString name) {
    this->_name = name;
}

void Currency::setCode(QString code) {
    this->_code = code;
}

void Currency::setMinorUnits(int minorUnits) {
    this->_minorUnits = minorUnits;
}
