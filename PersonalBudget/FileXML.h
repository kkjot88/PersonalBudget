#ifndef FILEXML_H
#define FILEXML_H

#include <cstring>
#include <string>
#include <fstream>

#include "Markup.h"
#include "Income.h"

using namespace std;

class FileXML {
	const string FILE_NAME;
	CMarkup xml;

	bool fileExists();

public:
	FileXML(string fileName);

	void addDataToFile(string TypeOfData);

};

#endif

