#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <algorithm>
#include <vector>

#include "Income.h"
#include "Expense.h"
#include "GeneralMethods.h"
#include "IncomesFileXML.h"
//#include "ExpenseFileXML.h"

using namespace std;

template <class  T>
class FinanceManager {
	vector<T> transactions;
	const int SIGNED_IN_USER_ID;
	IncomesFileXML incomesFileXML;

	Date askForDate();	
	T askForData(Date newDate);
	int generateNewId();	
	void showOneTransaction(T transaction);	
	void showTransactionsForGivenPeriod(vector<T> givenPeriodTransactions, Date startDate, Date endDate);
	vector<T> createVectorForGivenPeriod(Date startDate, Date endDate);
	double countTotalOfGivenTransactions(vector<T> givenTransactions);
	static bool compareByDates(T firstTransaction, T secondTransaction);

public:
	FinanceManager(string nameOfIncomesFileXML, int signedInUserId);

	void addTransaction();
	double showCurrentMonthTransactionsAndGetTotal();
	double showPreviousMonthTransactionsAndGetTotal();
	double showGivenPeriodTransactionsAndGetTotal();
};

//#include "FinanceManager.cpp"

#endif

