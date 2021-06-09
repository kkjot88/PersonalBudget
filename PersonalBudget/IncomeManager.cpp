#include "IncomeManager.h"

Date IncomeManager::askForIncomeDate() {	
	cout << "1. Today" << endl;
	cout << "2. Different date" << endl << endl;
	cout << "Your input: ";

	char userInput = GeneralMethods::readChar();	

	while (true) {
		if ((int)userInput == '1') {
			cout << endl << "Current date used." << endl;
			Date newDate;
			return newDate;
		}
		else if ((int)userInput == '2') {					
			Date newDate = GeneralMethods::readDate();
			return newDate;
		}
		else {
			cout << "Wrong input, try again" << endl;
		}
	}
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

	return newIncome;
}

int IncomeManager::generateNewIncomeId() {
	if (income.empty()) {
		return 1;
	}
	else {
		return income.back().getId() + 1;
	}
}

void IncomeManager::showOneIncome(Income singularIncome) {
	cout << "Id: " << singularIncome.getId() << " | " << singularIncome.getDate().getDate() << " | Amount: " << singularIncome.getAmount() << endl;
	cout << "                   | Description: " << singularIncome.getDescription() << endl;


	/*
	cout << "Id:                 " << income.getId() << endl;
	cout << "Date:               " << income.getDate().getDate() << endl;
	cout << "Description:        " << income.getDescription() << endl;
	cout << "Amount:             " << income.getAmount() << endl;
	cout << "-------------------------------------" << endl;
	*/
}

void IncomeManager::showIncomeForGivenPeriod(vector<Income> givenPeriodIncome, Date startDate, Date endDate) {
	system("cls");
	if (!givenPeriodIncome.empty()) {
		cout << "            >>> Income " << startDate.getDate() << "/" << endDate.getDate() << " <<<" << endl;
		cout << "-------------------------------------------------------------" << endl;

		for (vector<Income>::iterator itr = givenPeriodIncome.begin(); itr != givenPeriodIncome.end(); itr++)
		{
			showOneIncome(*itr);
		}
		cout << endl;
	}
	else {
		cout << endl << "No income in given period " << endl;
	}	
}

vector<Income> IncomeManager::createVectorForGivenPeriod(Date startDate, Date endDate) {
	vector<Income> givenPeriodIncome;
	for (int i = 0; i < income.size(); i++) {
		if (income[i].getDate() >= startDate && income[i].getDate() <= endDate) {
			givenPeriodIncome.push_back(income[i]);
		}
	}
	return givenPeriodIncome;
}

double IncomeManager::countSumOfIncomeInVector(vector<Income> incomeToSum) {
	double total = 0.0;
	for (int i = 0; i < incomeToSum.size(); i++) {
		total += incomeToSum[i].getAmount();
	}
	return total;
}

bool IncomeManager::compareIncomeByDates(Income firstIncome, Income secondIncome) {
	return (firstIncome.getDate() < secondIncome.getDate());
}

IncomeManager::IncomeManager(
	string nameOfIncomeFileXML,
	int signedInUserId
):
	//incomeFileXML(nameOfIncomeFileXML),
	SIGNED_IN_USER_ID(signedInUserId)
{
	//income = incomeFileXML.
}

void IncomeManager::addIncome() {
	Income newIncome;

	Date incomeDate = askForIncomeDate();
	newIncome = askForIncomeData(incomeDate);
	income.push_back(newIncome);

	incomeFileXML.addIncomeToFile();
	//save to xml?

	cout << "Income added successfully." << endl;
}

double IncomeManager::showCurrentMonthIncomeAndGetTotal(){
	Date firstDayOfCurrentMonth;
	firstDayOfCurrentMonth.setDay(1);

	Date lastDayOfCurrentMonth;	
	int lastDayNumber = lastDayOfCurrentMonth.getNumberOfDaysInMonth();
	lastDayOfCurrentMonth.setDay(lastDayNumber);

	vector<Income> currentMonthIncome;
	currentMonthIncome = createVectorForGivenPeriod(firstDayOfCurrentMonth,lastDayOfCurrentMonth);	

	sort(currentMonthIncome.begin(), currentMonthIncome.end(), compareIncomeByDates);

	showIncomeForGivenPeriod(currentMonthIncome,firstDayOfCurrentMonth,lastDayOfCurrentMonth);

	double total = countSumOfIncomeInVector(currentMonthIncome);
	return total;
}

double IncomeManager::showPreviousMonthIncomeAndGetTotal() {
	Date currentDate;
	int previousMonthNumber = currentDate.getMonth() - 1;

	Date firstDayOfPreviousMonth;
	firstDayOfPreviousMonth.setMonth(previousMonthNumber);
	firstDayOfPreviousMonth.setDay(1);

	Date lastDayOfPreviousMonth;
	lastDayOfPreviousMonth.setMonth(previousMonthNumber);
	int lastDayNumber = lastDayOfPreviousMonth.getNumberOfDaysInMonth();
	lastDayOfPreviousMonth.setDay(lastDayNumber);;

	vector<Income> previousMonthIncome;
	previousMonthIncome = createVectorForGivenPeriod(firstDayOfPreviousMonth, lastDayOfPreviousMonth);

	sort(previousMonthIncome.begin(), previousMonthIncome.end(), compareIncomeByDates);

	showIncomeForGivenPeriod(previousMonthIncome, firstDayOfPreviousMonth, lastDayOfPreviousMonth);

	double total = countSumOfIncomeInVector(previousMonthIncome);
	return total;
}

double IncomeManager::showGivenPeriodIncomeAndGetTotal() {
	Date firstDate = GeneralMethods::readDate();
	Date secondDate = GeneralMethods::readDate();

	vector<Income> givenPeriodIncome;
	givenPeriodIncome = createVectorForGivenPeriod(firstDate, secondDate);

	sort(givenPeriodIncome.begin(), givenPeriodIncome.end(), compareIncomeByDates);

	double total = countSumOfIncomeInVector(givenPeriodIncome);
	return total;
}
