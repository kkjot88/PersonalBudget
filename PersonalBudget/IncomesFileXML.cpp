#include "IncomesFileXML.h"

IncomesFileXML::IncomesFileXML(string nameOfIncomesFile) :
	FileXML(nameOfIncomesFile),
	lastIncomeId(0)
{
	CString fileName = nameOfIncomesFile.c_str();
	if (fileExists())
		xml.Load(fileName);
	else
		xml.Save(fileName);	
}

int IncomesFileXML::getLastIncomeId() {
	return lastIncomeId;
}

vector<Income> IncomesFileXML::loadIncomesFromFile(int signedInUserId) {
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

		lastIncomeId = stoi(GeneralMethods::CStringToString(idData));
	}	

	return incomes;
}

void IncomesFileXML::addIncomeToFile(Income income) {
	lastIncomeId = income.getUserId();

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
