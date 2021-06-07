#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "GeneralMethods.h"

using namespace std;

class UserManager {
	vector<User> users;
	int signedInUserId;

	User enterUserInfo();	
	bool doesLoginExists(string login);

public:
	UserManager(string NameOfUserFileXML);

	void showAllUsers();

	void signUp();
	bool isUserSignedIn();
	int generateNewUserId();
	int signIn();
};

#endif

