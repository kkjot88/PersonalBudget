template <class T>
FinanceManager<T>::FinanceManager(
	string nameOfTransactionsFileXML,
	int signedInUserId
) :
	transactionsFileXML(nameOfTransactionsFileXML),
	SIGNED_IN_USER_ID(signedInUserId)
{
	transactions = transactionsFileXML.loadTransactionsFromFile(SIGNED_IN_USER_ID);
}

template <class T>
Date FinanceManager<T>::askForDate() {
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

template<class T>
T FinanceManager<T>::askForData(Date newDate) {
	T transaction;

	transaction.setId(generateNewId());
	transaction.setUserId(SIGNED_IN_USER_ID);
	transaction.setDate(newDate.getDate());

	cout << "Enter description: ";
	string description = GeneralMethods::readLine();
	transaction.setDescription(description);

	cout << "Enter amount: ";
	double amount = GeneralMethods::readDouble();
	transaction.setAmount(amount);

	return transaction;
}

template<class T>
int FinanceManager<T>::generateNewId() {
	if (transactions.empty()) {
		return 1;
	}
	else {
		return transactionsFileXML.getLastIncomeId() + 1;
	}
}

template<class T>
void FinanceManager<T>::showOneTransaction(T transaction) {
	cout << "Id: " << transaction.getId();
	cout << " | " << transaction.getDate().getDate();
	cout << " | Amount: " << transaction.getAmount() << endl;
	cout << "                   | Description: " << transaction.getDescription() << endl;
}

template<class T>
void FinanceManager<T>::showTransactionsForGivenPeriod(vector<T> givenPeriodTransactions, Date startDate, Date endDate) {
	system("cls");
	if (!givenPeriodTransactions.empty()) {
		cout << "            >>> Transactions " << startDate.getDate() << "/" << endDate.getDate() << " <<<" << endl;
		cout << "-------------------------------------------------------------" << endl;

		for (typename vector<T>::iterator itr = givenPeriodTransactions.begin(); itr != givenPeriodTransactions.end(); itr++)
		{
			showOneTransaction(*itr);
		}
		cout << endl;
	}
	else {
		cout << endl << "No transactions in given period " << endl;
	}
}

template<class T>
vector<T> FinanceManager<T>::createVectorForGivenPeriod(Date startDate, Date endDate) {
	vector<T> givenPeriodVector;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions[i].getDate() >= startDate && transactions[i].getDate() <= endDate) {
			givenPeriodVector.push_back(transactions[i]);
		}
	}
	return givenPeriodVector;
}

template<class T>
double FinanceManager<T>::countTotalOfGivenTransactions(vector<T> givenTransactions) {
	double total = 0.0;
	for (int i = 0; i < givenTransactions.size(); i++) {
		total += givenTransactions[i].getAmount();
	}
	return total;
}

template<class T>
bool FinanceManager<T>::compareByDates(T firstTransaction, T secondTransaction) {
	return (firstTransaction.getDate() < secondTransaction.getDate());
}

template<class T>
void FinanceManager<T>::addTransaction() {
	T newTransaction;

	Date transactionDate = askForDate();
	newTransaction = askForData(transactionDate);
	transactions.push_back(newTransaction);

	//incomesFileXML.addIncomeToFile(newTransaction);

	cout << "Transaction added successfully." << endl;
}

template<class T>
double FinanceManager<T>::showCurrentMonthTransactionsAndGetTotal() {
	Date firstDayOfCurrentMonth;
	firstDayOfCurrentMonth.setDay(1);

	Date lastDayOfCurrentMonth;
	int lastDayNumber = lastDayOfCurrentMonth.getNumberOfDaysInMonth();
	lastDayOfCurrentMonth.setDay(lastDayNumber);

	vector<T> currentMonthTransactions;
	currentMonthTransactions = createVectorForGivenPeriod(firstDayOfCurrentMonth, lastDayOfCurrentMonth);

	sort(currentMonthTransactions.begin(), currentMonthTransactions.end(), compareByDates);

	showTransactionsForGivenPeriod(currentMonthTransactions, firstDayOfCurrentMonth, lastDayOfCurrentMonth);

	double total = countTotalOfGivenTransactions(currentMonthTransactions);
	return total;
}

template<class T>
double FinanceManager<T>::showPreviousMonthTransactionsAndGetTotal() {
	Date currentDate;
	int previousMonthNumber = currentDate.getMonth() - 1;

	Date firstDayOfPreviousMonth;
	firstDayOfPreviousMonth.setMonth(previousMonthNumber);
	firstDayOfPreviousMonth.setDay(1);

	Date lastDayOfPreviousMonth;
	lastDayOfPreviousMonth.setMonth(previousMonthNumber);
	int lastDayNumber = lastDayOfPreviousMonth.getNumberOfDaysInMonth();
	lastDayOfPreviousMonth.setDay(lastDayNumber);;

	vector<T> previousMonthTransactions;
	previousMonthTransactions = createVectorForGivenPeriod(firstDayOfPreviousMonth, lastDayOfPreviousMonth);

	sort(previousMonthTransactions.begin(), previousMonthTransactions.end(), compareByDates);

	showTransactionsForGivenPeriod(previousMonthTransactions, firstDayOfPreviousMonth, lastDayOfPreviousMonth);

	double total = countTotalOfGivenTransactions(previousMonthTransactions);
	return total;
}

template<class T>
double FinanceManager<T>::showGivenPeriodTransactionsAndGetTotal() {
	Date firstDate = GeneralMethods::readDate();
	Date secondDate = GeneralMethods::readDate();

	vector<T> givenPeriodTransactions;
	givenPeriodTransactions = createVectorForGivenPeriod(firstDate, secondDate);

	sort(givenPeriodTransactions.begin(), givenPeriodTransactions.end(), compareByDates);

	showTransactionsForGivenPeriod(givenPeriodTransactions, firstDate, secondDate);

	double total = countTotalOfGivenTransactions(givenPeriodTransactions);
	return total;
}

template class FinanceManager<Income>;
template class FinanceManager<Expense>;
