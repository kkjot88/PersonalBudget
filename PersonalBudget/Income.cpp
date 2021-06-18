#include "Income.h"

Income::Income() :
    id(0),
    userId(0),
    amount(0.0),
    description("")
{
    Date newDate("2000-01-01");
    date = newDate;
}

Income::Income(int _id, int _userId, Date _date, double _amount, string _description) :
    id(_id),
    userId(_userId),
    date(_date),
    description(_description),
    amount(_amount)
{
}

int Income::getId() {
    return id;
}

int Income::getUserId() {
    return userId;
}

Date Income::getDate() {
    return date;
}

string Income::getDescription() {
    return description;
}

double Income::getAmount() {
    return amount;
}

void Income::setId(int newId) {
    id = newId;
}

void Income::setUserId(int newUserId) {
    userId = newUserId;
}

void Income::setDate() {
    date.setDate();
}

void Income::setDate(string userDate) {
    date.setDate(userDate);
}

void Income::setDescription(string newDescription) {
    description = newDescription;
}

void Income::setAmount(int newAmount) {
    amount = newAmount;
}
