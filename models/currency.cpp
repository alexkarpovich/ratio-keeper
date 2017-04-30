#include "currency.h"

Currency::Currency(QObject * parent)
    : Base(parent)
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

Currency *Currency::getByNumber(int number)
{
    qDebug() << "Currency::getByNumber -" << number;

    QString sql = "select * from currency where number=:number";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":number", number);

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    if (query.next()) {
        Currency * currency = new Currency();

        currency->setNumber(number);
        currency->setName(query.value(1).toString());
        currency->setCode(query.value(2).toString());
        currency->setMinorUnits(query.value(3).toInt());
        currency->setCreatedAt(query.value(4).toDateTime());
        currency->setUpdatedAt(query.value(5).toDateTime());

        return currency;
    }

    return NULL;
}
