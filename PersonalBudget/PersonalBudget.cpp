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
	int userId = userManager.signIn();
	if (userManager.isUserSignedIn()) {		
		incomeManager = new IncomeManager(NAME_OF_INCOME_FILE_XML, userId);
		//expenseManager = new expenseManager(NAME_OF_EXPENSE_FILE_XML, userId);
	}
}

void PersonalBudget::userSignUp() {
	userManager.signUp();
}

bool PersonalBudget::isUserSignedIn() {
	return userManager.isUserSignedIn();
}

void PersonalBudget::addIncome() {
	if (userManager.isUserSignedIn())
		incomeManager->addIncome();
	else
		cout << "Not signed in" << endl;
}

void PersonalBudget::showCurrentMonthBalance() {
	double total = incomeManager->showCurrentMonthIncomesAndGetTotal();
	cout << total << endl;

}

void PersonalBudget::showPreviousMonthBalance() {
	double total = incomeManager->showPreviousMonthIncomesAndGetTotal();
	cout << total << endl;
}
