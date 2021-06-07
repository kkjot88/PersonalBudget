#include "GeneralMethods.h"

string GeneralMethods::readLine() {
    string entry = "";
    getline(cin, entry);
    return entry;
}

char GeneralMethods::readChar() {
    string entry = "";
    char enteredChar = { 0 };

    while (true)
    {
        getline(cin, entry);

        if (entry.length() == 1)
        {
            enteredChar = entry[0];
            break;
        }
        cout << "Not a single char. Try again." << endl;
    }
    return enteredChar;
}
