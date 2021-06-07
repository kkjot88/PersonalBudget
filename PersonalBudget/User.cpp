#include "User.h"

int User::getId() {
    return id;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getName() {
    return name;
}

string User::getSurname() {
    return surname;
}

void User::setId(int newId) {
    id = newId;
}

void User::setLogin(string newLogin) {
    login = newLogin;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}

void User::setName(string newName) {
    name = newName;
}

void User::setSurname(string newSurname) {
    surname = newSurname;
}
