#include "PersonalBudget.h"

using namespace std;

int main() {
	PersonalBudget personalBudget("users.xml", "incomes.xml", "expenses.xml");
	char userChoice;

	while (true) {
		if (personalBudget.isUserSignedIn() == 0) {
			userChoice = personalBudget.chooseOptionMainMenu();

			switch (userChoice) {
			case '1':
				personalBudget.userSignIn();
				break;
			case '2':
				personalBudget.userSignUp();
				break;
			case '9':
				exit(0);
				break;
			default:
				cout << endl << "No such option in menu." << endl << endl;
				system("pause");
				break;
			}
		}
		else {
			userChoice = personalBudget.chooseOptionUserMenu();

			switch (userChoice) {
			case '1':
				personalBudget.addIncome();
				break;
			case '2':
				personalBudget.addExpense();
				break;
			case '3':
				personalBudget.showCurrentMonthBalance();
				break;
			case '4':
				personalBudget.showPreviousMonthBalance();
				break;
			case '5':
				personalBudget.showGivenPeriodBalance();
				break;
			case '6':
				personalBudget.changeSignedInUserPassword();
				break;
			case '7':
				personalBudget.userSignOut();
				break;
			default:
				cout << endl << "No such option in menu." << endl << endl;
				system("pause");
				break;
			}
		}
	}

}
	
	
