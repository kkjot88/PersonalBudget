#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <vector>

#include "Income.h"
#include "Expense.h"

using namespace std;

class DateManager {

public:
	Date getCurrentDate();
	vector<Income> sortByDate(vector<Income> incomes);
	vector<Expense> sortByDate(vector<Expense> expenses);
	bool checkDate(string date);
};

#endif

