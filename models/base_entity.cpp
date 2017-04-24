#include "base_entity.h"

BaseEntity::BaseEntity()
{

}

uuid BaseEntity::getId() {
    return this->_id;
}

void BaseEntity::setId(const uuid id) {
    this->_id = id;
}
