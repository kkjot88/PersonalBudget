#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>
#include "Date.h"

using namespace std;

class Expense {
	int id, userId;
	Date date;
	string description;
	int amount;
public:
	int getId();
	int getUserId();
	Date getDate();
	string getDescription();
	int getAmount();

	void setId(int newId);
	void setUserId(int newUserId);
	void setDate();
	void setDate(string userDate);
	void setDescription(string newDescription);
	void setAmount(int newAmount);
};

#endif

