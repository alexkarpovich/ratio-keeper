#include "instance.h"

Instance::Instance()
{

}

QString Instance::getName() {
    return this->_name;
}

bool Instance::isActive() {
    return this->_active;
}

void Instance::setName(QString name) {
    this->_name = name;
}

void Instance::setActive(bool isActive) {
    this->_active = isActive;
}
