#ifndef FILEXML_H
#define FILEXML_H

#include <cstring>
#include <string>

#include "Markup.h"
#include "Income.h"

using namespace std;

class FileXML {
	const string FILE_NAME;
	
public:
	FileXML(string fileName);
	void addIncomeToFile(Income singularIncome);

};

#endif

