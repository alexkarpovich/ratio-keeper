#include "base_entity.h"

BaseEntity::BaseEntity(QObject * parent)
    : Base(parent)
{

}

uuid BaseEntity::genUuid() {
    char* id = new char[36];
    QByteArray ba = QUuid::createUuid().toByteArray();

    strcpy(id, (uuid) ba.mid(1, 36).data());

    return (uuid) id;
}

int BaseEntity::timestamp() {
    return QDateTime::currentDateTime().toTime_t();
}

uuid BaseEntity::getId() {
    return this->_id;
}

void BaseEntity::setId(uuid id) {
    this->_id = id;
}

void BaseEntity::setId(QByteArray id) {
    char* _id = new char[36];

    strcpy(_id, id.data());

    this->_id = (uuid) _id;
}
