#ifndef EXPENSE_CATEGORY_H
#define EXPENSE_CATEGORY_H

#include "base_entity.h"
#include "models/instance.h"

class ExpenseCategory : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(Instance* instance READ getInstance WRITE setInstance NOTIFY propChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY propChanged)
    Q_PROPERTY(QString icon READ getIcon WRITE setIcon NOTIFY propChanged)

protected:
    Instance * _instance;
    QString _name;
    QString _icon;
public:
    ExpenseCategory(QObject * parent = 0);
public slots:
    Instance* getInstance();
    QString getName();
    QString getIcon();
    void setInstance(Instance * instance);
    void setName(QString name);
    void setIcon(QString icon);

    static void createFromList(Instance * instance, QList<ExpenseCategory *> categoryList);
    static QList<ExpenseCategory *> getByInstanceId(uuid instanceId);
    static QList<ExpenseCategory *> getSystem();

signals:
    void propChanged();
};

#endif // EXPENSE_CATEGORY_H
