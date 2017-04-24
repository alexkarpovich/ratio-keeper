#include "user.h"

User::User()
{

}

QString User::getUsername() {
    return this->_username;
}

QString User::getEmail() {
    return this->_email;
}

QString User::getFirstName() {
    return this->_firstName;
}

QString User::getLastName() {
    return this->_lastName;
}

bool User::isActive() {
    return this->_active;
}

void User::setUsername(QString username) {
    this->_username = username;
}

void User::setEmail(QString email) {
    this->_email = email;
}

void User::setFirstName(QString firstName) {
    this->_firstName = firstName;
}

void User::setLastName(QString lastName) {
    this->_lastName = lastName;
}

void User::setActive(bool isActive) {
    this->_active = isActive;
}
