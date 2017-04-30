#include "expense_category.h"

ExpenseCategory::ExpenseCategory(QObject * parent)
    : BaseEntity(parent)
{

}

Instance* ExpenseCategory::getInstance() {
    return this->_instance;
}

QString ExpenseCategory::getName() {
    return this->_name;
}

QString ExpenseCategory::getDescription() {
    return this->_description;
}

void ExpenseCategory::setInstance(Instance *instance) {
    this->_instance = instance;
}

void ExpenseCategory::setName(QString name) {
    this->_name = name;
}

void ExpenseCategory::setDescription(QString description) {
    this->_description = description;
}

void ExpenseCategory::createFromList(Instance * instance, QStringList names) {
    qDebug() << "ExpenseCategory::createFromList -";

    int timestamp = ExpenseCategory::timestamp();
    QString sql = "insert into expense_category (id, instance_id, name, description, created_at, updated_at) values";

    QString ts = QString::number(timestamp);
    QStringList rows;
    foreach(const QString& name, names) {
        rows.append(QString("('%1','%2','%3','%4',%5,%6)")
                .arg(ExpenseCategory::genUuid(), instance->getId(), name, "", ts, ts));
    }
    sql += rows.join(", ");

    qDebug() << sql;

    QSqlQuery query;

    if (!query.exec(sql)) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return;
    }
}

QList<ExpenseCategory*> ExpenseCategory::getByInstanceId(uuid instanceId) {
    qDebug() << "ExpenseCategory::getByInstanceId -" << instanceId;

    QList<ExpenseCategory*> categoryList;
    QString sql = "select * from expense_category where instance_id=:instance_id";

    QSqlQuery query;
    query.prepare(sql);
    query.bindValue(":instance_id", QString(instanceId));

    if (!query.exec()) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return categoryList;
    }

    Instance * instance = Instance::getById(instanceId);

    while (query.next()) {
        ExpenseCategory * ctg = new ExpenseCategory();
        ctg->setId(query.value(0).toByteArray());
        ctg->setInstance(instance);
        ctg->setName(query.value(2).toString());
        ctg->setDescription(query.value(3).toString());
        ctg->setCreatedAt(query.value(4).toDateTime());
        ctg->setUpdatedAt(query.value(5).toDateTime());

        categoryList.append(ctg);
    }

    return categoryList;
}
