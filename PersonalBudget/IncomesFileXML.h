#ifndef INCOMEFILEXML_H
#define INCOMEFILEXML_H

#include <vector>

#include "FileXML.h"
#include "Income.h"
#include "GeneralMethods.h"

using namespace std;

class IncomesFileXML : FileXML {
	CMarkup xml;

public:
	IncomesFileXML(string nameOfIncomesFile);

	vector<Income> loadIncomesFromFile();
	void addIncomeToFile(Income income);

};

#endif

