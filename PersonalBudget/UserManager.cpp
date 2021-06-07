#include "UserManager.h"

User UserManager::enterUserInfo() {
    User user;

    user.setId(generateNewUserId());

    string login;
    do
    {
        cout << "Enter login: ";
        getline(cin, login);
        user.setLogin(login);
    } while (doesLoginExists(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    getline(cin, password);
    user.setPassword(password);

    return user;
}

int UserManager::generateNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::doesLoginExists(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "login already exists." << endl;
            return true;
        }
    }
    return false;
}

UserManager::UserManager(string NameOfUserFileXML) {
}

void UserManager::showAllUsers() {
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager::signUp() {
    User user = enterUserInfo();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "User signed up succesfully" << endl << endl;
    system("pause");
}

bool UserManager::isUserSignedIn() {
    if (signedInUserId > 0)
        return true;
    else
        return false;
}

int UserManager::signIn() {
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = GeneralMethods::readLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr->getLogin() == login)
        {
            for (int tryNumbers = 3; tryNumbers > 0; tryNumbers--)
            {
                cout << "Enter password. Remaining tries: " << tryNumbers << ": ";
                password = GeneralMethods::readLine();

                if (itr->getPassword() == password)
                {
                    cout << endl << "Sign in successful." << endl << endl;
                    system("pause");
                    signedInUserId = itr->getId();
                    return signedInUserId;
                }
            }
            cout << "Exceeded number of tries." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no user with given login" << endl << endl;
    system("pause");
    return 0;
}
