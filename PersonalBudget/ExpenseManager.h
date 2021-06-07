#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include "Expense.h"
#include "DateManager.h"

using namespace std;

class ExpenseManager {	
	vector<Expense> expenses;
	DateManager dateManager;
	const int SIGNED_IN_USER_ID;

public:
	ExpenseManager(string nameOfExpenseFileXML, int signedInUserId);

};

#endif

