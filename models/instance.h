#ifndef INSTANCE_H
#define INSTANCE_H

#include "base_entity.h"
#include "user.h"

class Instance : public BaseEntity
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName WRITE setName)
protected:
    QString _name;
public:
    Instance(QObject * parent = 0);
    QString getName();
    void setName(QString name);

    Instance * addUser(User * user);
    Instance * save();

    static Instance * getById(uuid instanceId);
    static Instance * getByUserId(uuid userId);
};

#endif // INSTANCE_H
