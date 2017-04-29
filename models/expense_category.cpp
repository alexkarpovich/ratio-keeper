#include "expense_category.h"

ExpenseCategory::ExpenseCategory()
{

}

QString ExpenseCategory::getName() {
    return this->_name;
}

QString ExpenseCategory::getDescription() {
    return this->_description;
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
