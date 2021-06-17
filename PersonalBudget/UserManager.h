#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "GeneralMethods.h"
#include "UsersFileXML.h"

using namespace std;

class UserManager {
	vector<User> users;
	int signedInUserId;
	UsersFileXML usersFileXML;

	User enterUserInfo();
	int generateNewUserId();
	bool doesLoginExists(string login);
	string getNewPassword(string oldPassword);

public:
	UserManager(string nameOfUserFileXML);

	void showAllUsers();

	void signUp();
	bool isUserSignedIn();	
	int signIn();
	void changePassword();
	void signOut();
};

#endif

