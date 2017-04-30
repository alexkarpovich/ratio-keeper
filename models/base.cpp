#include "base.h"

Base::Base(QObject *parent)
    : QObject(parent)
{

}

QDateTime Base::getCreatedAt() {
    return this->_createdAt;
}

QDateTime Base::getUpdatedAt() {
    return this->_updatedAt;
}

void Base::setCreatedAt(QDateTime createdAt) {
    this->_createdAt = createdAt;
}

void Base::setUpdatedAt(QDateTime updatedAt) {
    this->_updatedAt = updatedAt;
}
