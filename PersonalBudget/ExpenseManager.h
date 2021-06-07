#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <vector>
#include "Expense.h"

using namespace std;

class ExpenseManager {
	const int SIGNED_IN_USER_ID;
	vector<Expense> expenses;

public:
	ExpenseManager(string nameOfExpenseFileXML, int signedInUserId);

};

#endif

