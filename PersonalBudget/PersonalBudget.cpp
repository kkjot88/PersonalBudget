#include "PersonalBudget.h"

PersonalBudget::PersonalBudget(
	string nameOfUserFileXML, 
	string nameOfIncomesFileXML, 
	string nameOfExpensesFileXML
):
	userManager(nameOfUserFileXML),
	NAME_OF_INCOME_FILE_XML(nameOfIncomesFileXML),
	NAME_OF_EXPENSE_FILE_XML(nameOfExpensesFileXML)
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
		incomeManager = new FinanceManager<Income>(NAME_OF_INCOME_FILE_XML, userId);
		expenseManager = new FinanceManager<Expense>(NAME_OF_EXPENSE_FILE_XML, userId);
	}
}

void PersonalBudget::userSignUp() {
	userManager.signUp();
}

bool PersonalBudget::isUserSignedIn() {
	return userManager.isUserSignedIn();
}

char PersonalBudget::chooseOptionUserMenu() {
	char choice;

	system("cls");
	cout << "    >>> USER MENU <<<" << endl;
	cout << "---------------------------" << endl;
	cout << "1. Add income" << endl;
	cout << "2. Add expense" << endl;
	cout << "3. Show current month balance" << endl;
	cout << "4. Show previous month balance" << endl;
	cout << "5. Show given period balance" << endl;
	cout << "6. Change password" << endl;
	cout << "7. Sign out" << endl;
	cout << "---------------------------" << endl;
	cout << "Choose option: ";
	choice = GeneralMethods::readChar();

	return choice;
}

void PersonalBudget::addIncome() {
	if (userManager.isUserSignedIn())
		incomeManager->addTransaction();
	else
		cout << "Not signed in" << endl;
}

void PersonalBudget::addExpense() {
	if (userManager.isUserSignedIn())
		expenseManager->addTransaction();
	else
		cout << "Not signed in" << endl;
}

void PersonalBudget::showCurrentMonthBalance() {
	double totalIncome = incomeManager->showCurrentMonthTransactionsAndGetTotal();
	double totalExpense = expenseManager->showCurrentMonthTransactionsAndGetTotal();

	cout << "Total income: " << totalIncome << endl;
	cout << "Total expense: " << totalExpense << endl;
	cout << "Difference: " << totalIncome - totalExpense << endl;

}

void PersonalBudget::showPreviousMonthBalance() {
	double totalIncome = incomeManager->showPreviousMonthTransactionsAndGetTotal();
	double totalExpense = expenseManager->showPreviousMonthTransactionsAndGetTotal();

	cout << "Total income: " << totalIncome << endl;
	cout << "Total expense: " << totalExpense << endl;
	cout << "Difference: " << totalIncome - totalExpense << endl;
}

void PersonalBudget::showGivenPeriodBalance() {
	double totalIncome = incomeManager->showGivenPeriodTransactionsAndGetTotal();
	double totalExpense = expenseManager->showGivenPeriodTransactionsAndGetTotal();

	cout << "Total income: " << totalIncome << endl;
	cout << "Total expense: " << totalExpense << endl;
	cout << "Difference: " << totalIncome - totalExpense << endl;
}

void PersonalBudget::changeSignedInUserPassword() {
	if (userManager.isUserSignedIn()) 
		userManager.changePassword();
	else
		cout << "Not signed in" << endl;
}

void PersonalBudget::userSignOut() {
	userManager.signOut();
	delete incomeManager;
	incomeManager = NULL;
	delete expenseManager;
	expenseManager = NULL;
}
