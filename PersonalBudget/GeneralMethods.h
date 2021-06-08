#ifndef GENERALMETHODS_H
#define GENERALMETHODS_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class GeneralMethods {

public:
	static string readLine();
	static char readChar();
	static double readDouble();
	static string readDate();
	static int charToInt(char character);

};

#endif