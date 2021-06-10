#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "Income.h"
#include "GeneralMethods.h"
#include "IncomesFileXML.h"


using namespace std;

class IncomeManager {
	vector<Income> incomes;
	const int SIGNED_IN_USER_ID;
	IncomesFileXML incomeFileXML;

	Date askForIncomeDate();
	Income askForIncomeData(Date newDate);
	int generateNewIncomeId();
	void showOneIncome(Income Income);
	void showIncomesForGivenPeriod(vector<Income> givenPeriodIncomes, Date startDate, Date endDate);
	vector<Income> createVectorForGivenPeriod(Date startDate, Date endDate);
	double countSumOfIncomesInVector(vector<Income> incomesToSum);
	static bool compareIncomesByDates(Income firstIncome, Income secondIncome);
	
public:	
	IncomeManager(string nameOfIncomesFileXML, int signedInUserId);

	//void loadCurrentUserIncomes();
	void addIncome();
	double showCurrentMonthIncomesAndGetTotal();
	double showPreviousMonthIncomesAndGetTotal();
	double showGivenPeriodIncomesAndGetTotal();	
};

#endif

