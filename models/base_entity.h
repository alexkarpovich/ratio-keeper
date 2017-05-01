#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include <QUuid>
#include "base.h"

typedef const char* uuid;

class BaseEntity : public Base
{
    Q_PROPERTY(uuid id READ getId NOTIFY propChanged)
protected:
    uuid _id = NULL;
public:
    BaseEntity(QObject * parent = 0);

    uuid getId();
    void setId(uuid id);
    void setId(QByteArray id);

    static uuid genUuid();
    static int timestamp();

signals:
    void propChanged();
};

#endif // BASE_ENTITY_H
