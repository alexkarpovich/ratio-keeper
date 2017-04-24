#include "expense_category.h"

ExpenseCategory::ExpenseCategory()
{

}

QString ExpenseCategory::getName() {
    return this->_name;
}

void ExpenseCategory::setName(QString name) {
    this->_name = name;
}
