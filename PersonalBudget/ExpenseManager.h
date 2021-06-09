#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>

#include "Expense.h"


using namespace std;

class ExpenseManager {	
	vector<Expense> expenses;
	const int SIGNED_IN_USER_ID;

public:
	ExpenseManager(string nameOfExpenseFileXML, int signedInUserId);

};

#endif

