#ifndef USERSFILEXML_H
#define USERSFILEXML_H

#include <vector>

#include "FileXML.h"
#include "User.h"
#include "GeneralMethods.h"

using namespace std; 

class UsersFileXML : FileXML {
	CMarkup xml;
	int lastUserId;

public:
	UsersFileXML(string nameOfUsersFile);

	int getLastUserId();

	void changePasswordInFIle(int signedInUserId, string newPassword);
	vector<User> loadUsersFromFile();
	void addUserToFile(User user);

};

#endif