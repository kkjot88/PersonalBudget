#ifndef DATE_H
#define DATE_H

#define __STDC_WANT_LIB_EXT1__ 1
#include <string>
#include <time.h>

using namespace std;

class Date {
	int year, month, day;
	string date;

public:
	int getYear();
	int getMonth();
	int getDay();
	string getDate();

	//void setYear(int newYear);
	//void setMonth(int newMonth);
	//void setDay(int newDay);
	void setDate();
	void setDate(string newDate);
};

#endif

