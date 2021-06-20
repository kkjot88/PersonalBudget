#include "GeneralMethods.h"

string GeneralMethods::readLine() {
    string entry = "";
    while (entry.length() == 0) {
        getline(cin, entry);
        if(entry.length() == 0) {
            cout << "No text entered." << endl;
            cout << "Try again: ";
        }
    }  
    
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
        cout << "Not a single char." << endl;
        cout << "Try again: ";
    }
    return enteredChar;
}

double GeneralMethods::readDouble() {
    string entry = "";
    double correctDouble = 0.0;
    bool isNumber = false;    

    while (!isNumber) {
        getline(cin, entry);

        bool alreadyHasOneDotOrComma = false;
        int entryLength = entry.length();

        for (int i = 0; i < entryLength; i++) {
            if ((entry[i] >= 48 && entry[i] <= 57) || entry[i] == 44 || entry[i] == 46) {
                if (entry[i] == ',' || entry[i] == '.') {
                    entry[i] = '.';
                    if (alreadyHasOneDotOrComma) {
                        cout << "Wrong format, too many dots or commas." << endl;
                        cout << "Try again: ";
                        isNumber = false;
                        break;
                    }
                    alreadyHasOneDotOrComma = true;
                }
                isNumber = true;
            }
            else {
                cout << "Not a number." << endl;
                cout << "Try again: ";
                break;
            }                
        }        
    }
    correctDouble = stod(entry);

    return correctDouble;    
}

Date GeneralMethods::readDate() {
    string entry = "";    
    cout << "Enter date: ";

    while (true) {
        getline(cin, entry);

        int entryLength = entry.length();
        if (entryLength != 10) {
            cout << "Wrong format." << endl;
            cout << "Try again: ";
            continue;
        }

        for (int i = 0; i < 10; i++) {
            if (!((entry[i] >= 48 && entry[i] <= 57) || entry[i] == 45)) {
                cout << "Wrong format." << endl;
                cout << "Try again: ";
                continue;
            }
        }
        
        if (entry[4] != 45) {
            cout << "Wrong format." << endl;
            cout << "Try again: ";
            continue;
        }

        if (entry[7] != 45) {
            cout << "Wrong format." << endl;
            cout << "Try again: ";
            continue;
        }

        Date inputDate(entry);
        if (!inputDate.check()) {            
            cout << "Try again: ";
            continue;
        }

        return inputDate;
    }        
}

int GeneralMethods::charToInt(char character) {
    stringstream ss;
    int integer = 0;

    ss << character;
    ss >> integer;

    return integer;
}

string GeneralMethods::CStringToString(CString cstring) {    
    stringstream ss;
    string convertedCString;
    size_t size = (cstring.GetLength() + 1) * 4;
    char* buf = new char[size + 1];

    if (buf)
    {
        int lt = WideCharToMultiByte(CP_UTF8, 0, (LPCTSTR)cstring, cstring.GetLength() + 1, buf, size, 0, 0);
    }    

    ss << buf;
    ss >> convertedCString;

    return convertedCString;
}

void GeneralMethods::switchDates(Date& firstDate, Date& secondDate) {    
        Date tempDate = firstDate;
        firstDate = secondDate;
        secondDate = tempDate;
}
