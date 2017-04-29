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

Instance * Instance::addUser(User *user) {
    qDebug() << "Instance::addUser -";

    if (!this->getId()) {
        qDebug() << "No Instance created";
        return NULL;
    }

    QString sql = "insert into instance_user (instance_id, user_id, active) "
                  "values(:instance_id, :user_id, :isActive)";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":instance_id", this->getId());
    query.bindValue(":user_id", user->getId());
    query.bindValue(":isActive", true);

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    return this;
}

Instance* Instance::save() {
    qDebug() << "Instance::save -";

    int timestamp = BaseEntity::timestamp();
    QString sql = "update instance set (name, updated_at) "
                  "values(:name, :updated_at)";

    if (!this->getId()) {
        this->setId(BaseEntity::genUuid());

        sql = "insert into instance (id, name, created_at, updated_at) "
              "values(:id, :name, :created_at, :updated_at)";
    }

    qDebug() << "instance_id =" << this->getId();

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", QString(this->getId()));
    query.bindValue(":name", this->getName());
    query.bindValue(":created_at", timestamp);
    query.bindValue(":updated_at", timestamp);

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    return this;
}
