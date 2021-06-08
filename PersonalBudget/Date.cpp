#include "Date.h"

Date::Date() :date(getCurrentDate()) {
    extractYear();
    extractMonth();
    extractDay();
}

Date::Date(string newDate) :date(newDate) {
    extractYear();
    extractMonth();
    extractDay();
}

string Date::getCurrentDate() {
    struct tm currentTime;
    time_t now = time(0);
    localtime_s(&currentTime, &now);

    int currentYear = currentTime.tm_year + 1900;
    int currentMonth = currentTime.tm_mon + 1;
    int currentDay = currentTime.tm_mday;    

    string currentDate = to_string(currentYear) + "-" + monthIntToString(currentMonth) + "-" + dayIntToString(currentDay);

    return currentDate;
}

string Date::monthIntToString(int _month) {
    if (_month < 10)
        return ("0" + to_string(_month));    
    else
        return to_string(_month);    
}

string Date::dayIntToString(int _day) {
    if (_day < 10)
        return ("0" + to_string(_day));
    else
        return to_string(_day);
}

void Date::extractYear() {
    year = stoi(date.substr(0, 4));    
}

void Date::extractMonth() {
    month = stoi(date.substr(5, 2));
}

void Date::extractDay() {
    day = stoi(date.substr(8, 2));
}

bool Date::checkYear() {
    if (year >= 2000) 
        return true;    
    else
        return false;   
}

bool Date::checkMonth() {
    if (month > 0 && month <= 12)
        return true;
    else
        return false;
}

bool Date::checkDay() {    
    map<int, int> allMonthLength;
    if (year % 4 != 0) 
        allMonthLength = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
    else 
        allMonthLength = { {1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };

    int dayLimit;
    map<int, int>::iterator it;

    for (it = allMonthLength.begin(); it != allMonthLength.end(); it++) {
        if (month == it->first) 
            dayLimit = it->second;        
    }

    if (day > 0 && day <= dayLimit)
        return true;
    else
        return false;
}

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
    
}

void Date::setDate(string newDate) {
    date = newDate;
    extractYear();
    extractMonth();
    extractDay();    
}

bool Date::check() {    
    if (checkYear() == false)
        return false;

    if (checkMonth() == false)
        return false;

    if (checkDay() == false)
        return false;

    return true;
}
