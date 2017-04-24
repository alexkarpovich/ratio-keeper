#ifndef INSTANCE_H
#define INSTANCE_H

#include "base_entity.h"

class Instance : protected BaseEntity
{
    Q_PROPERTY(QString name READ getName WRITE setName)
    Q_PROPERTY(bool active READ isActive WRITE setActive)
protected:
    QString _name;
    bool _active;
public:
    Instance();
    QString getName();
    bool isActive();
    void setName(QString name);
    void setActive(bool isActive);
};

#endif // INSTANCE_H
