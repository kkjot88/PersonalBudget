#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>

#include "Income.h"
#include "DateManager.h"
#include "GeneralMethods.h"


using namespace std;

class IncomeManager {
	vector<Income> incomes;
	DateManager dateManager;
	const int SIGNED_IN_USER_ID;

	Date askForIncomeDate();
	Income askForIncomeData(Date newDate);
	int generateNewIncomeId();
	//void addIncomeToFile();
	//void showIncomes();
	
public:
	IncomeManager(string nameOfIncomeFileXML, int signedInUserId);

	//void loadCurrentUserIncomes();
	void addIncome();
	//void showCurrentMonthIncomes();
	//void showPreviousMonthIncomes();
	//void showGivenPeriodIncomes();
};

#endif

