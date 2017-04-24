#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "base.h"

typedef char* uuid;

class BaseEntity : protected Base
{
    Q_PROPERTY(uuid id READ getId WRITE setId)
protected:
    uuid _id;
public:
    BaseEntity();
    uuid getId();
    void setId(uuid id);
};

#endif // BASE_ENTITY_H
