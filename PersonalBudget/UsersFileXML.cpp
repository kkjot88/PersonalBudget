#include "UsersFileXML.h"

UsersFileXML::UsersFileXML(string nameOfUsersFile) :
	FileXML(nameOfUsersFile),
	lastUserId(0)
{
	CString fileName = nameOfUsersFile.c_str();
	if (fileExists())
		xml.Load(fileName);
	else
		xml.Save(fileName);
}

int UsersFileXML::getLastUserId() {
	return lastUserId;
}

vector<User> UsersFileXML::loadUsersFromFile() {
	vector<User> users;

	CString const USER("USER");
	CString const ID("ID");
	CString const NAME("NAME");
	CString const SURNAME("SURNAME");
	CString const LOGIN("LOGIN");
	CString const PASSWORD("PASSWORD");

	while (xml.FindElem(USER)) {
		xml.IntoElem();
		xml.FindElem(ID);
		CString idData = xml.GetData();
		xml.FindElem(NAME);
		CString nameData = xml.GetData();
		xml.FindElem(SURNAME);
		CString surnameData = xml.GetData();
		xml.FindElem(LOGIN);
		CString loginData = xml.GetData();
		xml.FindElem(PASSWORD);
		CString passwordData = xml.GetData();
		xml.OutOfElem();

		
		int id = stoi(GeneralMethods::CStringToString(idData));
		string name = GeneralMethods::CStringToString(nameData);
		string surname = GeneralMethods::CStringToString(surnameData);
		string login = GeneralMethods::CStringToString(loginData);
		string password = GeneralMethods::CStringToString(passwordData);

		User user(id, name, surname, login, password);

		users.push_back(user);		

		lastUserId = stoi(GeneralMethods::CStringToString(idData));
	}

	return users;
}

void UsersFileXML::addUserToFile(User user) {
	lastUserId = user.getId();

	CString const USER("USER");

	CString const ID("ID");
	CString id = to_string(user.getId()).c_str();
	CString const NAME("NAME");
	CString name = user.getName().c_str();
	CString const SURNAME("SURNAME");
	CString surname = user.getSurname().c_str();
	CString const LOGIN("LOGIN");
	CString login = user.getLogin().c_str();
	CString const PASSWORD("PASSWORD");
	CString password = user.getPassword().c_str();

	xml.AddElem(USER);
	xml.IntoElem();
	xml.AddElem(ID, id);
	xml.AddElem(NAME, name);
	xml.AddElem(SURNAME, surname);
	xml.AddElem(LOGIN, login);
	xml.AddElem(PASSWORD, password);
	xml.OutOfElem();
	xml.Save(FileXML::getFileName());
}
