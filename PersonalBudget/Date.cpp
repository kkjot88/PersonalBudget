#include "Date.h"

int Date::getYear() {
    return year;
}

int Date::getMonth() {
    return month;
}

int Date::getDay() {
    return day;
}

string Date::getDate() {
    return date;
}

void Date::setDate() {
    //get current date via time.h/ctime
}

void Date::setDate(string newDate) {
    date = newDate;
}
