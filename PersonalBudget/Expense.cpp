#include "Expense.h"

int Expense::getId() {
    return id;
}

int Expense::getUserId() {
    return userId;
}

Date Expense::getDate() {
    return date;
}

string Expense::getDescription() {
    return description;
}

int Expense::getAmount() {
    return amount;
}

void Expense::setId(int newId) {
    id = newId;
}

void Expense::setUserId(int newUserId) {
    userId = newUserId;
}

void Expense::setDate() {
    //date obtained with ctime
}

void Expense::setDate(string userDate) {
    date.setDate(userDate);
}

void Expense::setDescription(string newDescription) {
    description = newDescription;
}

void Expense::setAmount(int newAmount) {
    amount = newAmount;
}