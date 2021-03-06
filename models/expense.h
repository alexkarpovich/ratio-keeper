#ifndef EXPENSE_H
#define EXPENSE_H

#include "base_entity.h"
#include "expense_category.h"
#include "user.h"

class Expense : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(ExpenseCategory* category READ getCategory WRITE setCategory NOTIFY propChanged)
    Q_PROPERTY(User* user READ getUser WRITE setUser NOTIFY propChanged)
    Q_PROPERTY(float value READ getValue WRITE setValue NOTIFY propChanged)

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

signals:
    void propChanged();
};

#endif // EXPENSE_H
