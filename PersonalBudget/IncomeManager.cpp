#include "IncomeManager.h"

Date IncomeManager::askForIncomeDate() {	
	Date newDate;

	cout << "1. Today" << endl;
	cout << "2. Different date" << endl << endl;
	cout << "Your input: ";
	bool isInputCorrect = false;

	while (!isInputCorrect) {
		char userInput = GeneralMethods::readChar();

		if ((int)userInput == '1') {
			cout << endl << "Current date used." << endl;
			newDate.setDate();
			isInputCorrect = true;
		}
		else if ((int)userInput == '2') {
			cout << endl << "Enter date: ";
			string newDateString = GeneralMethods::readLine();	
			newDate.setDate(newDateString);
			isInputCorrect = true;
		}
		else {
			cout << "Wrong input, try again" << endl;
		}
	}

	return newDate;
}

Income IncomeManager::askForIncomeData(Date newDate) {
	Income newIncome;

	newIncome.setId(generateNewIncomeId());
	newIncome.setUserId(SIGNED_IN_USER_ID);
	newIncome.setDate(newDate.getDate());

	cout << "Enter income description: ";
	string description = GeneralMethods::readLine();
	newIncome.setDescription(description);

	cout << "Enter income amount: ";
	double amount = GeneralMethods::readDouble();
	newIncome.setAmount(amount);

	return Income();
}

int IncomeManager::generateNewIncomeId() {
	if (incomes.empty()) {
		return 1;
	}
	else {
		return incomes.back().getId() + 1;
	}
}

IncomeManager::IncomeManager(
	string nameOfIncomeFileXML,
	int signedInUserId
):
	//incomeFileXML(nameOfIncomeFileXML),
	SIGNED_IN_USER_ID(signedInUserId)
{
	//incomes = incomeFileXML.
}

void IncomeManager::addIncome() {
	Income newIncome;

	Date incomeDate = askForIncomeDate();
	newIncome = askForIncomeData(incomeDate);
	incomes.push_back(newIncome);

	//save to xml?

	cout << "Income added successfully." << endl;
}
