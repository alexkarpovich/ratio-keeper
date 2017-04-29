#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include <QUuid>
#include "base.h"

typedef const char* uuid;

class BaseEntity : public Base
{
    Q_PROPERTY(uuid id READ getId WRITE setId)
protected:
    uuid _id = NULL;
public:
    BaseEntity();
    uuid getId();
    void setId(uuid id);

    static uuid genUuid();
    static int timestamp();
};

#endif // BASE_ENTITY_H
