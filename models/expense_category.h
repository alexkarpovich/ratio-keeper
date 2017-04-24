#ifndef EXPENSE_CATEGORY_H
#define EXPENSE_CATEGORY_H

#include "base_entity.h"

class ExpenseCategory : protected BaseEntity
{
    Q_PROPERTY(QString name READ getName WRITE setName)

protected:
    QString _name;
public:
    ExpenseCategory();
    QString getName();
    void setName(QString name);
};

#endif // EXPENSE_CATEGORY_H
