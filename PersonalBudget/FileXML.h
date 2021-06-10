#ifndef FILEXML_H
#define FILEXML_H

#include <cstring>
#include <string>
#include <fstream>

#include "Markup.h"
#include "Income.h"

using namespace std;

class FileXML {
	const CString FILE_NAME;		

public:
	FileXML(string fileName);

	CString getFileName();

	bool fileExists();

};

#endif

