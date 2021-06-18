#ifndef GENERALMETHODS_H
#define GENERALMETHODS_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <afx.h>

#include "Date.h"

using namespace std;

class GeneralMethods {

public:
	static string readLine();
	static char readChar();
	static double readDouble();
	static Date readDate();
	static int charToInt(char character);
	static string CStringToString(CString cstring);
	static string doubleToStringWithTwoDigitsAfterDecimalPoint(double _double);
	static void switchDates(Date &firstDate, Date &secondDate);

};

#endif