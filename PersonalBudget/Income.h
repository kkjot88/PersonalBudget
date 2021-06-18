#ifndef INCOME_H
#define INCOME_H

#include <string>

#include "Date.h"

using namespace std;

class Income {
	int id, userId;
	Date date;	
	double amount;
	string description;

public:
	Income();
	Income(int _id, int _userId, Date _date, double _amount, string _description);

	int getId();
	int getUserId();
	Date getDate();
	string getDescription();
	double getAmount();

	void setId(int newId);
	void setUserId(int newUserId);
	void setDate();
	void setDate(string userDate);
	void setDescription(string newDescription);
	void setAmount(int newAmount);

};

#endif

