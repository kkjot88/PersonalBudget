#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <algorithm>

#include "Income.h"
#include "DateManager.h"
#include "GeneralMethods.h"


using namespace std;

class IncomeManager {
	//vector<Income> incomes;
	DateManager dateManager;
	const int SIGNED_IN_USER_ID;

	Date askForIncomeDate();
	Income askForIncomeData(Date newDate);
	int generateNewIncomeId();
	//void addIncomeToFile();
	//void showIncomes();
	vector<Income> createVectorForGivenPeriod(Date startDate, Date endDate);
	double countSumOfIncomesInVector(vector<Income> incomesToSum);
	static bool compareIncomesByDates(Income firstIncome, Income secondIncome);
	
public:
	vector<Income> incomes;
	IncomeManager(string nameOfIncomeFileXML, int signedInUserId);

	//void loadCurrentUserIncomes();
	void addIncome();
	double showCurrentMonthIncomesAndGetTotal();
	double showPreviousMonthIncomesAndGetTotal();
	double showGivenPeriodIncomesAndGetTotal();
};

#endif

