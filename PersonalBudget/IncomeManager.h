#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <vector>
#include "Income.h"

using namespace std;

class IncomeManager {
	const int SIGNED_IN_USER_ID;
	vector<Income> incomes;
	
public:
	IncomeManager(string nameOfIncomeFileXML, int signedInUserId);

};

#endif

