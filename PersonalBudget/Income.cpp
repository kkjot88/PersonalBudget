#include "Income.h"

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

int Income::getAmount() {
    return amount;
}

void Income::setId(int newId) {
    id = newId;
}

void Income::setUserId(int newUserId) {
    userId = newUserId;
}

void Income::setDate() {
    //date obtained with ctime
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
