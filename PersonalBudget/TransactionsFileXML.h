#ifndef INCOMESFILEXML_H
#define INCOMESFILEXML_H

#include <vector>

#include "FileXML.h"
#include "Income.h"
#include "Expense.h"
#include "GeneralMethods.h"

using namespace std;

template<class T>
class TransactionsFileXML : FileXML {
	CMarkup xml;
	int lastTransactionId;

public:
	TransactionsFileXML(string nameOfTransactionsFile);

	int getLastIncomeId();

	vector<T> loadTransactionsFromFile(int signedInUserId);
	void addTransactionToFile(T transaction);

};

#include "TransactionsFileXML.cpp"

#endif

