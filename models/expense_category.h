#ifndef EXPENSE_CATEGORY_H
#define EXPENSE_CATEGORY_H

#include "base_entity.h"
#include "models/instance.h"

class ExpenseCategory : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(Instance* instance READ getInstance WRITE setInstance NOTIFY propChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY propChanged)
    Q_PROPERTY(QString description READ getDescription WRITE setDescription NOTIFY propChanged)

protected:
    Instance * _instance;
    QString _name;
    QString _description;
public:
    ExpenseCategory(QObject * parent = 0);
public slots:
    Instance* getInstance();
    QString getName();
    QString getDescription();
    void setInstance(Instance * instance);
    void setName(QString name);
    void setDescription(QString description);

    static void createFromList(Instance * instance, QStringList names);
    static QList<ExpenseCategory*> getByInstanceId(uuid instanceId);

signals:
    void propChanged();
};

#endif // EXPENSE_CATEGORY_H
