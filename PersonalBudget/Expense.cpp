#include "Expense.h"

Expense::Expense() :
    id(0),
    userId(0),
    amount(0.0),
    description("")
{
    Date newDate("2000-01-01");
    date = newDate;
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
    date.setDate();
}

void Expense::setDate(string userDate) {
    date.setDate(userDate);
}

void Expense::setDescription(string newDescription) {
    description = newDescription;
}

void Expense::setAmount(double newAmount) {
    amount = newAmount;
}