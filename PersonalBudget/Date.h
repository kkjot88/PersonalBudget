#ifndef DATE_H
#define DATE_H

#define __STDC_WANT_LIB_EXT1__ 1
#include <string>
#include <time.h>
#include <map>

using namespace std;

class Date {
	int year, month, day;
	string date;

	string getCurrentDate();
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
	
	void setDate();
	void setDate(string newDate);

	bool check();
};

#endif

