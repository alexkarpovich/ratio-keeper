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

User* User::save() {
    qDebug() << "User::save -";

    int timestamp = BaseEntity::timestamp();
    QString sql = "update user set (username, email, first_name, last_name, active, updated_at) "
                  "values(:username, :email, :first_name, :last_name, :isActive, :updated_at)";

    if (!this->getId()) {
        this->setId(BaseEntity::genUuid());

        sql = "insert into user (id, username, email, first_name, last_name, active, created_at, updated_at) "
              "values(:id, :username, :email, :first_name, :last_name, :isActive, :created_at, :updated_at)";
    }

    qDebug() << "user_id =" << this->getId();

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", QString(this->getId()));
    query.bindValue(":username", this->getUsername());
    query.bindValue(":email", this->getEmail());
    query.bindValue(":first_name", this->getFirstName());
    query.bindValue(":last_name", this->getLastName());
    query.bindValue(":isActive", this->isActive());
    query.bindValue(":created_at", timestamp);
    query.bindValue(":updated_at", timestamp);

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    return this;
}
