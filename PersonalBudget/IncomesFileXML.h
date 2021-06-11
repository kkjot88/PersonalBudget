#ifndef INCOMESFILEXML_H
#define INCOMESFILEXML_H

#include <vector>

#include "FileXML.h"
#include "Income.h"
#include "GeneralMethods.h"

using namespace std;

class IncomesFileXML : FileXML {
	CMarkup xml;
	int lastIncomeId;

public:
	IncomesFileXML(string nameOfIncomesFile);

	int getLastIncomeId();

	vector<Income> loadIncomesFromFile(int signedInUserId);
	void addIncomeToFile(Income income);

};

#endif

