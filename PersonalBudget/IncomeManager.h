#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "Income.h"
#include "GeneralMethods.h"
#include "FileXML.h"


using namespace std;

class IncomeManager {
	//vector<Income> income;
	const int SIGNED_IN_USER_ID;
	FileXML incomeFileXML;

	Date askForIncomeDate();
	Income askForIncomeData(Date newDate);
	int generateNewIncomeId();
	void showOneIncome(Income singularIncome);
	void showIncomeForGivenPeriod(vector<Income> givenPeriodIncome, Date startDate, Date endDate);
	vector<Income> createVectorForGivenPeriod(Date startDate, Date endDate);
	double countSumOfIncomeInVector(vector<Income> incomeToSum);
	static bool compareIncomeByDates(Income firstIncome, Income secondIncome);
	
public:
	vector<Income> income;
	IncomeManager(string nameOfIncomeFileXML, int signedInUserId);

	//void loadCurrentUserIncome();
	void addIncome();
	double showCurrentMonthIncomeAndGetTotal();
	double showPreviousMonthIncomeAndGetTotal();
	double showGivenPeriodIncomeAndGetTotal();	
};

#endif

