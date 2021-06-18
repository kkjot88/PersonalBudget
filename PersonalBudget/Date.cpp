#include "Date.h"

Date::Date() :date(getCurrentDate()) {
    extractYear();
    extractMonth();
    extractDay();
    if (year % 4 != 0)
        allMonthLength = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
    else
        allMonthLength = { {1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
}

Date::Date(string newDate) :date(newDate) {
    extractYear();
    extractMonth();
    extractDay();
    if (year % 4 != 0)
        allMonthLength = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
    else
        allMonthLength = { {1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
}

string Date::getCurrentDate() {
    struct tm currentTime;
    time_t now = time(0);
    localtime_s(&currentTime, &now);

    int currentYear = currentTime.tm_year + 1900;
    int currentMonth = currentTime.tm_mon + 1;
    int currentDay = currentTime.tm_mday;    

    string currentDate = combineIntoDate(currentYear, currentMonth, currentDay);

    return currentDate;
}

string Date::combineIntoDate(int _year, int _month, int _day) {
    string combinedDate = to_string(_year) + "-" + monthIntToString(_month) + "-" + dayIntToString(_day);
    return combinedDate;
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
    else {
        cout << "Wrong date, must be later than 1999-12-31." << endl;
        return false;
    }         
}

bool Date::checkMonth() {
    if (month > 0 && month <= 12)
        return true;
    else {
        cout << "Wrong month number, must be in range from 1 to 12." << endl;
    }
        return false;
}

bool Date::checkDay() {
    if (day > 0 && day <= getNumberOfDaysInMonth())
        return true;
    else {      
        cout << "Wrong day number, must be in rage from 1 to " << getNumberOfDaysInMonth() << "." << endl;
        return false;
    }
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

void Date::setYear(int newYear) {
    year = newYear;
    extractMonth();
    extractDay();
    date = combineIntoDate(newYear, month, day);
}

void Date::setMonth(int newMonth) {
    extractYear();
    month = newMonth;
    extractDay();
    date = combineIntoDate(year, newMonth, day);
}

void Date::setDay(int newDay) {
    extractYear();
    extractMonth();
    day = newDay;
    date = combineIntoDate(year, month, newDay);
}

void Date::setDate() {
    date = getCurrentDate();
    extractYear();
    extractMonth();
    extractDay();
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

int Date::getNumberOfDaysInMonth(){
    return allMonthLength[month];
}

bool Date::operator==(Date secondDate) {
    if (this->year == secondDate.year &&
        this->month == secondDate.month &&
        this->day == secondDate.day
        )
        return true;
    else
        return false;
}

bool Date::operator>(Date secondDate) {
    if (this->year > secondDate.year)
        return true;
    else if (this->year < secondDate.year)
        return false;

    if (this->month > secondDate.month)
        return true;
    else if (this->month < secondDate.month)
        return false;

    if (this->day > secondDate.day)
        return true;
    else
        return false;    
}

bool Date::operator<(Date secondDate) {
    if (this->year < secondDate.year)
        return true;
    else if (this->year > secondDate.year)
        return false;

    if (this->month < secondDate.month)
        return true;
    else if (this->month > secondDate.month)
        return false;

    if (this->day < secondDate.day)
        return true;
    else
        return false;
}

bool Date::operator>=(Date secondDate) {
    if (this->year > secondDate.year)
        return true;
    else if (this->year < secondDate.year)
        return false;

    if (this->month > secondDate.month)
        return true;
    else if (this->month < secondDate.month)
        return false;

    if (this->day >= secondDate.day)
        return true;
    else
        return false;
}

bool Date::operator<=(Date secondDate) {
    if (this->year < secondDate.year)
        return true;
    else if (this->year > secondDate.year)
        return false;

    if (this->month < secondDate.month)
        return true;
    else if (this->month > secondDate.month)
        return false;

    if (this->day <= secondDate.day)
        return true;
    else
        return false;
}
