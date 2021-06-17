#include "User.h"

User::User() {

}

User::User(int _id, string _name, string _surname, string _login, string _password) :
    id(_id),
    name(_name),
    surname(_surname),
    login(_login),
    password(_password)
{
}

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
