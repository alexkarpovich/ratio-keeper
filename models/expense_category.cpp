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

QString ExpenseCategory::getIcon() {
    return this->_icon;
}

void ExpenseCategory::setInstance(Instance *instance) {
    this->_instance = instance;
}

void ExpenseCategory::setName(QString name) {
    this->_name = name;
}

void ExpenseCategory::setIcon(QString value) {
    this->_icon = value;
}

void ExpenseCategory::createFromList(Instance * instance, QList<QObject *> categoryList) {
    qDebug() << "ExpenseCategory::createFromList -";

    int timestamp = ExpenseCategory::timestamp();
    QString sql = "insert into expense_category (id, instance_id, name, icon, created_at, updated_at) values";

    QString ts = QString::number(timestamp);
    QStringList rows;
    foreach(const QObject * ctg, categoryList) {
        rows.append(QString("('%1','%2','%3','%4',%5,%6)").arg(
                        ExpenseCategory::genUuid(),
                        instance->getId(),
                        ctg->property("name").toString(),
                        ctg->property("icon").toString(), ts, ts)
                    );
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
        ctg->setIcon(query.value(3).toString());
        ctg->setCreatedAt(query.value(4).toDateTime());
        ctg->setUpdatedAt(query.value(5).toDateTime());

        categoryList.append(ctg);
    }

    return categoryList;
}

QList<ExpenseCategory *> ExpenseCategory::getSystem()
{
    qDebug() << "ExpenseCategory::getSystem -";

    QList<ExpenseCategory*> categoryList;
    QString sql = "select * from expense_category where system=1";

    QSqlQuery query;

    if (!query.exec(sql)) {
        qDebug() << query.lastError();
        qDebug() << query.lastQuery();

        return categoryList;
    }

    while (query.next()) {
        ExpenseCategory * ctg = new ExpenseCategory();
        ctg->setName(query.value(2).toString());
        ctg->setIcon(query.value(4).toString());

        categoryList.append(ctg);
    }

    return categoryList;
}
