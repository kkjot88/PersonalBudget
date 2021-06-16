#include "Expense.h"

Expense::Expense() {
}

Expense::Expense(int _id, int _userId, Date _date, double _amount, string _description) :
    id(_id),
    userId(_userId),
    date(_date),
    description(_description),
    amount(_amount)
{
}

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

double Expense::getAmount() {
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