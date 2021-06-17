#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <string>

#include "UserManager.h"
#include "FinanceManager.h"

using namespace std;

class PersonalBudget {
	UserManager userManager;
	FinanceManager<Income>* incomeManager;
	FinanceManager<Expense>* expenseManager;
	const string NAME_OF_INCOME_FILE_XML;
	const string NAME_OF_EXPENSE_FILE_XML;

public:
	PersonalBudget(string nameOfUserFileXML, string nameOfIncomesFileXML, string nameOfExpenseFileXML);
	~PersonalBudget();

	void showAllUsers();

	char chooseOptionMainMenu();
	void userSignIn();
	void userSignUp();
	bool isUserSignedIn();

	char chooseOptionUserMenu();
	void addIncome();
	void addExpense();
	void showCurrentMonthBalance();
	void showPreviousMonthBalance();
	void showGivenPeriodBalance();
	void changeSignedInUserPassword();
	void userSignOut();
};

#endif