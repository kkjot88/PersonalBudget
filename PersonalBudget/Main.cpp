#include <iostream>
#include <vector>

#include "PersonalBudget.h"
#include "Date.h"
#include "Income.h"
#include "IncomeManager.h"
#include "IncomesFileXML.h"

using namespace std;

#define c cout <<
#define e << endl

int main() {
	IncomeManager incomeManager("Incomes.xml", 1);
	system("pause");	
}
	
	
