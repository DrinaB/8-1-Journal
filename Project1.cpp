/* Drina Baptiste
Project 1
CS210
07/20/240
*/


#include <iostream>
#include <string>

using namespace std;

int seconds = 0;
int minutes = 0; 
int hours = 0; 

int getSecond() {
    return seconds;
}

void setSecond(int s) {
    seconds = s;
}

int getMinute() {
    return minutes;
}

void setMinute(int m) {
    minutes = m;
}

int getHour() {
    return hours;
}

void setHour(int h) {
    hours = h;
}

void addOneHour() {
    hours = (hours + 1) % 24;
}

void addOneMinute() {
    minutes = (minutes + 1) % 60;
    if (minutes == 0) {
        addOneHour(); 
    }
}


void addOneSecond() {
    int currentSeconds = getSecond();
    if (currentSeconds >= 0 && currentSeconds < 59) {
        setSecond(currentSeconds + 1);
    } else if (currentSeconds == 59) {
        setSecond(0);
        addOneMinute();
    }
}


string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + to_string(n);
    } else {
        return to_string(n);
    }
}


string nCharString(size_t n, char c) {
    return string(n, c);
}


string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}


string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string period = (h >= 12) ? "P M" : "A M";
    unsigned int hour12 = h % 12;
    if (hour12 == 0) hour12 = 12; 
    return twoDigitString(hour12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + period;
}


void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27, '*') + nCharString(3, ' ') + nCharString(27, '*') << endl;
    cout << "*      12-HOUR CLOCK      *" + nCharString(3, ' ') + "*      24-HOUR CLOCK      *" << endl;
    cout << endl;
    cout << "*      " + formatTime12(h, m, s) + "      *" + nCharString(3, ' ') + "*      " + formatTime24(h, m, s) + "      *" << endl;
    cout << nCharString(27, '*') + nCharString(3, ' ') + nCharString(27, '*') << endl;
}


void printMenu(char* strings[], unsigned int numStrings, unsigned char width) {
    
    cout << nCharString(width, '*') << endl;

    
    for (unsigned int i = 0; i < numStrings; ++i) {
        string item = "* " + to_string(i + 1) + " - " + strings[i];
        unsigned int spaces = width - 1 - item.length(); 
        item += nCharString(spaces, ' ') + "*";
        cout << item << endl;
        if (i < numStrings - 1) {
            cout << endl; 
        }
    }

    
    cout << nCharString(width, '*') << endl;
}

void displayMenu() {
    const char* menuItems[] = {
        "Add one Hour",
        "Add one Minute",
        "Add one Second",
        "Exit program"
    };
    unsigned int numItems = sizeof(menuItems) / sizeof(menuItems[0]);
    printMenu(const_cast<char**>(menuItems), numItems, 30);
}


unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    while (true) {
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice) {
            break;
        }
    }
    return choice;
}

void addOneHour(int &hour) {
    hour = (hour + 1) % 24;
}

void addOneMin(int &min) {
    min = (min + 1) % 60;
}


void mainMenu() {
    int hour12 = 12, min12 = 0, sec12 = 0;
    int hour24 = 0, min24 = 0, sec24 = 0;

    while (true) {
        displayMenu();
        unsigned int userInput = getMenuChoice(4);

        if (userInput == 4) {
            cout << "Exiting program.\n";
            break;
        }

        switch (userInput) {
            case 1:
                addOneHour(hour24);
                break;
            case 2:
                addOneMin(min24);
                break;
            case 3:
                addOneSecond();
                break;
            default:
                cout << "Invalid choice. Please select again.\n";
                continue;
        }

        displayClocks(hour24, min24, sec24);
    }

    displayClocks(hour24, min24, sec24);
}

int main() {
    mainMenu();
    return 0;
}
