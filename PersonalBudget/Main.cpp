#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
	PersonalBudget personalBudget("x", "x", "x");

	personalBudget.userSignUp();
	
	personalBudget.userSignIn();

	personalBudget.showAllUsers();
}
