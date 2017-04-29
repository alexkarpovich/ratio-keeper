#ifndef EXPENSE_CATEGORY_H
#define EXPENSE_CATEGORY_H

#include "base_entity.h"
#include "models/instance.h"

class ExpenseCategory : public BaseEntity
{
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription)

protected:
    QString _name;
    QString _description;
public:
    ExpenseCategory();
public slots:
    QString getName();
    QString getDescription();
    void setName(QString name);
    void setDescription(QString description);

    static void createFromList(Instance * instance, QStringList names);
};

#endif // EXPENSE_CATEGORY_H
