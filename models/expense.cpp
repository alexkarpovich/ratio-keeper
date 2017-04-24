#include "expense.h"

Expense::Expense()
{

}

ExpenseCategory * Expense::getCategory() {
    return this->_category;
}

User * Expense::getUser() {
    return this->_user;
}

float Expense::getValue() {
    return this->_value;
}

void Expense::setCategory(ExpenseCategory * category) {
    this->_category = category;
}

void Expense::setUser(User *user) {
    this->_user = user;
}

void Expense::setValue(float value) {
    this->_value = value;
}
