#include "instance.h"

Instance::Instance(QObject * parent)
    : BaseEntity(parent)
{

}

QString Instance::getName() {
    return this->_name;
}

void Instance::setName(QString name) {
    this->_name = name;
}

Instance * Instance::getById(uuid instanceId) {
    qDebug() << "Instance::getById -" << instanceId;

    QString sql = "select * from instance where id=:id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":id", QString(instanceId));

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    if (query.next()) {
        Instance * instance = new Instance();
        instance->setId(instanceId);
        instance->setName(query.value(1).toString());
        instance->setCreatedAt(query.value(2).toDateTime());
        instance->setUpdatedAt(query.value(3).toDateTime());

        return instance;
    }

    return NULL;
}

Instance * Instance::getByUserId(uuid userId) {
    qDebug() << "Instance::getByUserId -" << userId;

    QString sql = "select ins.* from instance ins "
                  "join instance_user iu on ins.id=iu.instance_id and iu.user_id=:user_id";
    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":user_id", QString(userId));

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return NULL;
    }

    if (query.next()) {
        Instance * instance = new Instance();
        instance->setId(query.value(0).toByteArray());
        instance->setName(query.value(1).toString());
        instance->setCreatedAt(query.value(2).toDateTime());
        instance->setUpdatedAt(query.value(3).toDateTime());

        return instance;
    }

    return NULL;
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

    int timestamp = Instance::timestamp();
    QString sql = "update instance set (name, updated_at) "
                  "values(:name, :updated_at)";

    if (!this->getId()) {
        this->setId(Instance::genUuid());

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
