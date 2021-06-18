#ifndef DATE_H
#define DATE_H

#define __STDC_WANT_LIB_EXT1__ 1
#include <iostream>
#include <string>
#include <time.h>
#include <map>

using namespace std;

class Date {
	int year, month, day;
	string date;

	map<int, int> allMonthLength;

	string getCurrentDate();
	string combineIntoDate(int _year, int _month, int _day);
	string monthIntToString(int _month);
	string dayIntToString(int _day);
	void extractYear();
	void extractMonth();
	void extractDay();	
	bool checkYear();
	bool checkMonth();
	bool checkDay();

public:
	Date();
	Date(string newDate);

	int getYear();
	int getMonth();
	int getDay();
	string getDate();
	
	void setYear(int newYear);
	void setMonth(int newMonth);
	void setDay(int newDay);
	void setDate();
	void setDate(string newDate);

	bool check();
	int getNumberOfDaysInMonth();

	bool operator==(Date secondDate);
	bool operator>(Date secondDate);
	bool operator<(Date secondDate);
	bool operator>=(Date secondDate);
	bool operator<=(Date secondDate);

};

#endif

