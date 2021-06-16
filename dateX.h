#ifndef DATE_H
#define DATE_H

#define __STDC_WANT_LIB_EXT1__ 1
#include <string>
#include <time.h>
#include <map>

using namespace std;

class Date {
	string year, month, day;
	int date;

	map<int, int> allMonthLength;

	void getCurrentYearMonthDay();
	void combineIntoDate();	
	string extractYear(string dateString);
	string extractMonth(string dateString);
	string extractDay(string dateString);
	string formatMonth(string monthToFormat);
	string formatDay(string dayToFormat);
	bool checkYear();
	bool checkMonth();
	bool checkDay();	

public:
	Date();
	Date(string newDate);

	string getYear();
	string getMonth();
	string getDay();
	int getDate();
	string getFormatedDateString();

	void setYear(string newYear);
	void setMonth(string newMonth);
	void setDay(string newDay);
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

