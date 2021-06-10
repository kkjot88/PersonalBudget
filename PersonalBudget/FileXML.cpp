#include "FileXML.h"

bool FileXML::fileExists() {
	ifstream f(FILE_NAME);
	return f.good();
}

FileXML::FileXML(string fileName)
	:FILE_NAME(fileName.c_str())
{
	
}

CString FileXML::getFileName() {
	return FILE_NAME;
}
