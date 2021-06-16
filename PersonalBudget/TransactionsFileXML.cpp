template <class T>
TransactionsFileXML<T>::TransactionsFileXML(string nameOfTransactionsFile) :
	FileXML(nameOfTransactionsFile),
	lastTransactionId(0)
{
	CString fileName = nameOfTransactionsFile.c_str();
	if (fileExists())
		xml.Load(fileName);
	else
		xml.Save(fileName);	
}

template <class T>
int TransactionsFileXML<T>::getLastIncomeId() {
	return lastTransactionId;
}

template <class T>
vector<T> TransactionsFileXML<T>::loadTransactionsFromFile(int signedInUserId) {
	vector<T> transactions;

	CString const TRANSACTION("TRANSACTION");
	CString const ID("ID");	
	CString const USER_ID("USERID");	
	CString const DATE("DATE");	
	CString const AMOUNT("AMOUNT");	
	CString const DESCRIPTION("DESCRIPTION");	

	while (xml.FindElem(TRANSACTION)) {
		xml.IntoElem();
		xml.FindElem(ID);
		CString idData = xml.GetData();
		xml.FindElem(USER_ID);
		CString userIdData = xml.GetData();
		xml.FindElem(DATE);
		CString dateData = xml.GetData();
		xml.FindElem(AMOUNT);
		CString amountData = xml.GetData();
		xml.FindElem(DESCRIPTION);
		CString descriptionData = xml.GetData();
		xml.OutOfElem();

		if (stoi(GeneralMethods::CStringToString(userIdData)) == signedInUserId) {
			int id = stoi(GeneralMethods::CStringToString(idData));
			int userId = stoi(GeneralMethods::CStringToString(userIdData));
			Date date(GeneralMethods::CStringToString(dateData));
			double amount = stod(GeneralMethods::CStringToString(amountData));
			string description = GeneralMethods::CStringToString(descriptionData);

			T transaction(id, userId, date, amount, description);

			transactions.push_back(transaction);
		}		

		lastTransactionId = stoi(GeneralMethods::CStringToString(idData));
	}	

	return transactions;
}

template <>
inline vector<Income> TransactionsFileXML<Income>::loadTransactionsFromFile(int signedInUserId) {
	vector<Income> incomes;

	CString const INCOME("INCOME");
	CString const ID("ID");
	CString const USER_ID("USERID");
	CString const DATE("DATE");
	CString const AMOUNT("AMOUNT");
	CString const DESCRIPTION("DESCRIPTION");

	while (xml.FindElem(INCOME)) {
		xml.IntoElem();
		xml.FindElem(ID);
		CString idData = xml.GetData();
		xml.FindElem(USER_ID);
		CString userIdData = xml.GetData();
		xml.FindElem(DATE);
		CString dateData = xml.GetData();
		xml.FindElem(AMOUNT);
		CString amountData = xml.GetData();
		xml.FindElem(DESCRIPTION);
		CString descriptionData = xml.GetData();
		xml.OutOfElem();

		if (stoi(GeneralMethods::CStringToString(userIdData)) == signedInUserId) {
			int id = stoi(GeneralMethods::CStringToString(idData));
			int userId = stoi(GeneralMethods::CStringToString(userIdData));
			Date date(GeneralMethods::CStringToString(dateData));
			double amount = stod(GeneralMethods::CStringToString(amountData));
			string description = GeneralMethods::CStringToString(descriptionData);

			Income income(id, userId, date, amount, description);

			incomes.push_back(income);
		}

		lastTransactionId = stoi(GeneralMethods::CStringToString(idData));
	}

	return incomes;
}

template <>
inline vector<Expense> TransactionsFileXML<Expense>::loadTransactionsFromFile(int signedInUserId) {
	vector<Expense> expenses;

	CString const EXPENSE("EXPENSE");
	CString const ID("ID");
	CString const USER_ID("USERID");
	CString const DATE("DATE");
	CString const AMOUNT("AMOUNT");
	CString const DESCRIPTION("DESCRIPTION");

	while (xml.FindElem(EXPENSE)) {
		xml.IntoElem();
		xml.FindElem(ID);
		CString idData = xml.GetData();
		xml.FindElem(USER_ID);
		CString userIdData = xml.GetData();
		xml.FindElem(DATE);
		CString dateData = xml.GetData();
		xml.FindElem(AMOUNT);
		CString amountData = xml.GetData();
		xml.FindElem(DESCRIPTION);
		CString descriptionData = xml.GetData();
		xml.OutOfElem();

		if (stoi(GeneralMethods::CStringToString(userIdData)) == signedInUserId) {
			int id = stoi(GeneralMethods::CStringToString(idData));
			int userId = stoi(GeneralMethods::CStringToString(userIdData));
			Date date(GeneralMethods::CStringToString(dateData));
			double amount = stod(GeneralMethods::CStringToString(amountData));
			string description = GeneralMethods::CStringToString(descriptionData);

			Expense expense(id, userId, date, amount, description);

			expenses.push_back(expense);
		}

		lastTransactionId = stoi(GeneralMethods::CStringToString(idData));
	}

	return expenses;
}

template <class T>
void TransactionsFileXML<T>::addTransactionToFile(T transaction) {
	lastTransactionId = transaction.getUserId();

	CString const TRANSACTION("TRANSACTION");

	CString const ID("ID");
	CString id = to_string(transaction.getId()).c_str();
	CString const USER_ID("USERID");
	CString userId = to_string(transaction.getUserId()).c_str();
	CString const DATE("DATE");
	CString date = transaction.getDate().getDate().c_str();
	CString const AMOUNT("AMOUNT");
	CString amount = to_string(transaction.getAmount()).c_str();
	CString const DESCRIPTION("DESCRIPTION");
	CString description = transaction.getDescription().c_str();

	xml.AddElem(TRANSACTION);
	xml.IntoElem();
	xml.AddElem(ID, id);
	xml.AddElem(USER_ID, userId);
	xml.AddElem(DATE, date);
	xml.AddElem(AMOUNT, amount);
	xml.AddElem(DESCRIPTION, description);
	xml.OutOfElem();
	xml.Save(FileXML::getFileName());
}

template <>
inline void TransactionsFileXML<Income>::addTransactionToFile(Income income) {
	lastTransactionId = income.getUserId();

	CString const INCOME("INCOME");

	CString const ID("ID");
	CString id = to_string(income.getId()).c_str();
	CString const USER_ID("USERID");
	CString userId = to_string(income.getUserId()).c_str();
	CString const DATE("DATE");
	CString date = income.getDate().getDate().c_str();
	CString const AMOUNT("AMOUNT");
	CString amount = to_string(income.getAmount()).c_str();
	CString const DESCRIPTION("DESCRIPTION");
	CString description = income.getDescription().c_str();

	xml.AddElem(INCOME);
	xml.IntoElem();
	xml.AddElem(ID, id);
	xml.AddElem(USER_ID, userId);
	xml.AddElem(DATE, date);
	xml.AddElem(AMOUNT, amount);
	xml.AddElem(DESCRIPTION, description);
	xml.OutOfElem();
	xml.Save(FileXML::getFileName());
}

template <>
inline void TransactionsFileXML<Expense>::addTransactionToFile(Expense expense) {
	lastTransactionId = expense.getUserId();

	CString const EXPENSE("EXPENSE");

	CString const ID("ID");
	CString id = to_string(expense.getId()).c_str();
	CString const USER_ID("USERID");
	CString userId = to_string(expense.getUserId()).c_str();
	CString const DATE("DATE");
	CString date = expense.getDate().getDate().c_str();
	CString const AMOUNT("AMOUNT");
	CString amount = to_string(expense.getAmount()).c_str();
	CString const DESCRIPTION("DESCRIPTION");
	CString description = expense.getDescription().c_str();

	xml.AddElem(EXPENSE);
	xml.IntoElem();
	xml.AddElem(ID, id);
	xml.AddElem(USER_ID, userId);
	xml.AddElem(DATE, date);
	xml.AddElem(AMOUNT, amount);
	xml.AddElem(DESCRIPTION, description);
	xml.OutOfElem();
	xml.Save(FileXML::getFileName());
}

template class TransactionsFileXML<Income>;
template class TransactionsFileXML<Expense>;