#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(
	string nameOfUserFileXML, 
	string nameOfIncomeFileXML, 
	string nameOfExpenseFileXML
):
	userManager(nameOfUserFileXML),
	NAME_OF_INCOME_FILE_XML(nameOfIncomeFileXML),
	NAME_OF_EXPENSE_FILE_XML(nameOfExpenseFileXML)
{
	incomeManager = NULL;
	expenseManager = NULL;
}

PersonalBudget::~PersonalBudget() {
	delete incomeManager;
	incomeManager = NULL;
	delete expenseManager;
	expenseManager = NULL;
}

void PersonalBudget::showAllUsers() {
	userManager.showAllUsers();
}

char PersonalBudget::chooseOptionMainMenu() {
	char choice;

	system("cls");
	cout << "    >>> MAIN MENU <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Sign in" << endl;
	cout << "2. Sign up" << endl;
	cout << "9. Exit" << endl;
	cout << "---------------------------" << endl;
	cout << "Choose option: ";
	choice = GeneralMethods::readChar();

	return choice;
}

void PersonalBudget::userSignIn() {
	userManager.signIn();
	if (userManager.isUserSignedIn()) {
		int newUserId = userManager.generateNewUserId();
		incomeManager = new IncomeManager(NAME_OF_INCOME_FILE_XML, newUserId);
		//expenseManager = new expenseManager(NAME_OF_EXPENSE_FILE_XML, newUserId);
	}
}

void PersonalBudget::userSignUp() {
	userManager.signUp();
}

bool PersonalBudget::isUserSignedIn() {
	return userManager.isUserSignedIn();
}
