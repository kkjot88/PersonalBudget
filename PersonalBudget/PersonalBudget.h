#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <string>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class PersonalBudget {
	UserManager userManager;
	IncomeManager* incomeManager;
	ExpenseManager* expenseManager;
	const string NAME_OF_INCOME_FILE_XML;
	const string NAME_OF_EXPENSE_FILE_XML;

public:
	PersonalBudget(string nameOfUserFileXML, string nameOfIncomeFileXML, string nameOfExpenseFileXML);
	~PersonalBudget();

	void showAllUsers();

	char chooseOptionMainMenu();
	void userSignIn();
	void userSignUp();
	bool isUserSignedIn();

	void addIncome();
	//void addExpense();
	void showCurrentMonthBalance();
	void showPreviousMonthBalance();

};

#endif