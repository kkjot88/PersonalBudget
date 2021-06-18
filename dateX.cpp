#include "Date.h"

Date::Date() {
    getCurrentYearMonthDay();
    combineIntoDate();
    
    if (stoi(year) % 4 != 0)
        allMonthLength = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
    else
        allMonthLength = { {1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
}

Date::Date(string newDate) {
    year = extractYear(newDate);
    month = extractMonth(newDate);
    day = extractDay(newDate);
    combineIntoDate();

    if (stoi(year) % 4 != 0)
        allMonthLength = { {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
    else
        allMonthLength = { {1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
}

void Date::getCurrentYearMonthDay() {
    struct tm currentTime;
    time_t now = time(0);
    localtime_s(&currentTime, &now);

    year = to_string(currentTime.tm_year + 1900);
    month = to_string(currentTime.tm_mon + 1);
    day = to_string(currentTime.tm_mday);
}

void Date::combineIntoDate() {
    date = stoi(year + month + day);
}

string Date::extractYear(string dateString) {
    return dateString.substr(0, 4);
}

string Date::extractMonth(string dateString) {    
    return formatMonth(dateString.substr(5, 2));
}

string Date::extractDay(string dateString) {
    return formatDay(dateString.substr(8, 2));
}

string formatMonth(string monthToFormat) {
    if (monthToFormat.length() = 1)
        return ("0" + monthToFormat);
    else
        return monthToFormat;
}

string formatDay(string dayToFormat) {
    if (dayToFormat.length() = 1)
        return ("0" + dayToFormat);
    else
        return dayToFormat;
}

bool Date::checkYear() {
    if (stoi(year) >= 2000)
        return true;
    else
        return false;
}

bool Date::checkMonth() {
    if (stoi(month) > 0 && stoi(month) <= 12)
        return true;
    else
        return false;
}

bool Date::checkDay() {
    if (stoi(day) > 0 && stoi(day) <= getNumberOfDaysInMonth())
        return true;
    else
        return false;
}

string getYear() {
    return year;
}

string getMonth() {
    return month;
}
string getDay() {
    return day;
}

int getDate() {
    return date;
}

string getFormatedDateString() {
    return (to_string(year) + "-" + formatMonth(to_string(month)) + "-" + formatDay(to_string(day)));
}

void setYear(string newYear) {
    year = newYear;
    combineIntoDate();
}

void setMonth(string newMonth) {
    month = formatMonth(newMonth);
    combineIntoDate();
}

void setDay(string newDay) {
    day = formatDay(newDay);
    combineIntoDate();
}

void setDate() {
    getCurrentYearMonthDay();
    combineIntoDate();
}

void setDate(string newDate) {
    year = extractYear(newDate);
    month = extractMonth(newDate);
    day = extractDay(newDate);
    combineIntoDate();
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

int Date::getNumberOfDaysInMonth() {
    return allMonthLength[month];
}

bool Date::operator==(Date secondDate) {
    if (this->date == secondDate.date)
        return true;
    else
        return false;
}

bool Date::operator>(Date secondDate) {
    if (this->date > secondDate.date)
        return true;
    else
        return false;
}

bool Date::operator<(Date secondDate) 
    if (this->date < secondDate.date)
        return true;
    else
        return false;
}

bool Date::operator>=(Date secondDate) {
    if (this->date >= secondDate.date)
        return true;
    else
        return false;
}

bool Date::operator<=(Date secondDate) {
    if (this->date <= secondDate.date)
        return true;
    else
        return false;
}
