#ifndef CURRENCY_H
#define CURRENCY_H

#include "base.h"

class Currency : public Base
{
    Q_OBJECT
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY propChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY propChanged)
    Q_PROPERTY(QString code READ getCode WRITE setCode NOTIFY propChanged)
    Q_PROPERTY(int minorUnits READ getMinorUnits WRITE setMinorUnits NOTIFY propChanged)

protected:
    int _number;
    QString _name;
    QString _code;
    int _minorUnits;
public:
    Currency(QObject * parent = 0);
    int getNumber();
    QString getName();
    QString getCode();
    int getMinorUnits();
    void setNumber(int number);
    void setName(QString name);
    void setCode(QString code);
    void setMinorUnits(int minorUnits);

    static Currency *getByNumber(int number);
    static QList<Currency *> getAll();

signals:
    void propChanged();
};

#endif // CURRENCY_H
