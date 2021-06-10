#include "IncomesFileXML.h"

IncomesFileXML::IncomesFileXML(string nameOfIncomesFile) 
	:FileXML(nameOfIncomesFile)
{
	CString fileName = nameOfIncomesFile.c_str();
	if (fileExists())
		xml.Load(fileName);
	else
		xml.Save(fileName);
}

vector<Income> IncomesFileXML::loadIncomesFromFile() {
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
		CString id = xml.GetData();
		xml.FindElem(USER_ID);
		CString userId = xml.GetData();
		xml.FindElem(DATE);
		CString date = xml.GetData();
		xml.FindElem(AMOUNT);
		CString amount = xml.GetData();
		xml.FindElem(DESCRIPTION);
		CString description = xml.GetData();
		xml.OutOfElem();

		int x = stoi(GeneralMethods::CStringToString(id));
		int y = stoi(GeneralMethods::CStringToString(userId));

		//Income income(),
			
			
			
		//,userId,date,amount,description);
	}


	return incomes;
}

void IncomesFileXML::addIncomeToFile(Income income) {
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
	xml.AddElem(ID, id);
	xml.AddElem(USER_ID, userId);
	xml.AddElem(DATE, date);
	xml.AddElem(AMOUNT, amount);
	xml.AddElem(DESCRIPTION, description);
	xml.Save(FileXML::getFileName());
}
