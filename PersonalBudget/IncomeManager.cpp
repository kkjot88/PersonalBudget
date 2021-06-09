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
			cout << endl << "Enter date: ";
			Date newDate = GeneralMethods::readDate();

			if (!newDate.check()) {
				cout << "Wrong date. Try again." << endl;
				continue;
			}
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
	if (incomes.empty()) {
		return 1;
	}
	else {
		return incomes.back().getId() + 1;
	}
}

vector<Income> IncomeManager::createVectorForGivenPeriod(Date startDate, Date endDate) {
	vector<Income> givenPeriodIncomes;
	for (int i = 0; i < incomes.size(); i++) {
		if (incomes[i].getDate() >= startDate && incomes[i].getDate() <= endDate) {
			givenPeriodIncomes.push_back(incomes[i]);
		}
	}
	return givenPeriodIncomes;
}

double IncomeManager::countSumOfIncomesInVector(vector<Income> incomesToSum) {
	double total = 0.0;
	for (int i = 0; i < incomesToSum.size(); i++) {
		total += incomesToSum[i].getAmount();
	}
	return total;
}

bool IncomeManager::compareIncomesByDates(Income firstIncome, Income secondIncome) {
	return (firstIncome.getDate() < secondIncome.getDate());
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

double IncomeManager::showCurrentMonthIncomesAndGetTotal(){
	Date firstDayOfCurrentMonth;
	firstDayOfCurrentMonth.setDay(1);

	Date lastDayOfCurrentMonth;	
	int lastDayNumber = lastDayOfCurrentMonth.getNumberOfDaysInMonth();
	lastDayOfCurrentMonth.setDay(lastDayNumber);

	vector<Income> currentMonthIncomes;
	currentMonthIncomes = createVectorForGivenPeriod(firstDayOfCurrentMonth,lastDayOfCurrentMonth);	

	sort(currentMonthIncomes.begin(), currentMonthIncomes.end(), compareIncomesByDates);

	double total = countSumOfIncomesInVector(currentMonthIncomes);
	return total;
}

double IncomeManager::showPreviousMonthIncomesAndGetTotal() {
	Date currentDate;
	int previousMonthNumber = currentDate.getMonth() - 1;

	Date firstDayOfPreviousMonth;
	firstDayOfPreviousMonth.setMonth(previousMonthNumber);
	firstDayOfPreviousMonth.setDay(1);

	Date lastDayOfPreviousMonth;
	lastDayOfPreviousMonth.setMonth(previousMonthNumber);
	int lastDayNumber = lastDayOfPreviousMonth.getNumberOfDaysInMonth();
	lastDayOfPreviousMonth.setDay(lastDayNumber);;

	vector<Income> previousMonthIncomes;
	previousMonthIncomes = createVectorForGivenPeriod(firstDayOfPreviousMonth, lastDayOfPreviousMonth);

	sort(previousMonthIncomes.begin(), previousMonthIncomes.end(), compareIncomesByDates);

	double total = countSumOfIncomesInVector(previousMonthIncomes);
	return total;
}

double IncomeManager::showGivenPeriodIncomesAndGetTotal() {
	Date firstDate = GeneralMethods::readDate();
	Date secondDate = GeneralMethods::readDate();

	vector<Income> givenPeriodIncomes;
	givenPeriodIncomes = createVectorForGivenPeriod(firstDate, secondDate);

	sort(givenPeriodIncomes.begin(), givenPeriodIncomes.end(), compareIncomesByDates);

	double total = countSumOfIncomesInVector(givenPeriodIncomes);
	return total;
}
