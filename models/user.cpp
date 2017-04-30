#include "user.h"

User::User(QObject * parent)
    : BaseEntity(parent)
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

User* User::getActiveUser() {
    qDebug() << "User::getActiveUser -";

    QString sql = "select * from user where active=1";
    QSqlQuery query;

    if (!query.exec(sql)) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    if (query.next()) {
        User * user = new User();

        user->setId(query.value(0).toByteArray());
        user->setUsername(query.value(1).toString());
        user->setEmail(query.value(2).toString());
        user->setFirstName(query.value(3).toString());
        user->setLastName(query.value(4).toString());
        user->setActive(query.value(5).toBool());
        user->setCreatedAt(query.value(6).toDateTime());
        user->setUpdatedAt(query.value(7).toDateTime());

        return user;
    }

    return NULL;
}

User *User::getById(uuid id)
{
    qDebug() << "User::getById -" << id;

    QString sql = "select * from user where id=:id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", QString(id));

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    if (query.next()) {
        User * user = new User();

        user->setId(query.value(0).toByteArray());
        user->setUsername(query.value(1).toString());
        user->setEmail(query.value(2).toString());
        user->setFirstName(query.value(3).toString());
        user->setLastName(query.value(4).toString());
        user->setActive(query.value(5).toBool());
        user->setCreatedAt(query.value(6).toDateTime());
        user->setUpdatedAt(query.value(7).toDateTime());

        return user;
    }

    return NULL;
}

User* User::save() {
    qDebug() << "User::save -";

    int timestamp = User::timestamp();
    QString sql = "update user set (username, email, first_name, last_name, active, updated_at) "
                  "values(:username, :email, :first_name, :last_name, :isActive, :updated_at)";

    if (!this->getId()) {
        this->setId(User::genUuid());

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
