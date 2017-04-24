#ifndef CURRENCY_H
#define CURRENCY_H

#include "base.h"

class Currency : protected Base
{
    Q_PROPERTY(int number READ getNumber WRITE setNumber)
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString code READ getCode WRITE setCode)
    Q_PROPERTY(int minorUnits READ getMinorUnits WRITE setMinorUnits)

protected:
    int _number;
    QString _name;
    QString _code;
    int _minorUnits;
public:
    Currency();
    int getNumber();
    QString getName();
    QString getCode();
    int getMinorUnits();
    void setNumber(int number);
    void setName(QString name);
    void setCode(QString code);
    void setMinorUnits(int minorUnits);
};

#endif // CURRENCY_H
