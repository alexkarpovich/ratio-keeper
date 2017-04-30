#ifndef EXPENSE_H
#define EXPENSE_H

#include "base_entity.h"
#include "expense_category.h"
#include "user.h"

class Expense : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(ExpenseCategory* category READ getCategory WRITE setCategory)
    Q_PROPERTY(User* user READ getUser WRITE setUser)
    Q_PROPERTY(float value READ getValue WRITE setValue)

protected:
    ExpenseCategory * _category;
    User * _user;
    float _value;
public:
    Expense(QObject * parent = 0);
    ExpenseCategory * getCategory();
    User * getUser();
    float getValue();
    void setCategory(ExpenseCategory * category);
    void setUser(User * user);
    void setValue(float value);
};

#endif // EXPENSE_H
