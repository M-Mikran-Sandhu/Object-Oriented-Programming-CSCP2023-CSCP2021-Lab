#include <iostream>
#include <string>
#include <cstdlib>   
using namespace std;

class BankAccount {
private:
    string owner;
    int accountNo;
    double balance;

public:
    
    bool setOwner(string o) {
        if (o.empty()) {
            return false;
        }
        owner = o;
        return true;
    }

    bool setAccountNo(int a) {
        if (a < 1000 || a > 9999) {      
            return false;
        }
        accountNo = a;
        return true;
    }

    bool setBalance(double b) {
        if (b < 0) {                     
            return false;
        }
        balance = b;
        return true;
    }

  
    string getOwner() {
        return owner;
    }

    int getAccountNo() {
        return accountNo;
    }

    double getBalance() {
        return balance;
    }
};


void stopIfInputEnded() {
    if (cin.eof()) {
        cout << "\nInput ended. Exiting." << endl;
        exit(1);
    }
}

string readText(string prompt) {
    string text;
    cout << prompt;
    getline(cin, text);
    stopIfInputEnded();
    return text;
}

int readInt(string prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        stopIfInputEnded();
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "That is not a whole number. Try again: ";
    }
    cin.ignore(1000, '\n');
    return value;
}

double readDouble(string prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        stopIfInputEnded();
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "That is not a number. Try again: ";
    }
    cin.ignore(1000, '\n');
    return value;
}


void askOwner(BankAccount &acc) {
    while (!acc.setOwner(readText("Owner name: "))) {
        cout << "Rejected: name must not be empty." << endl;
    }
}

void askAccountNo(BankAccount &acc) {
    while (!acc.setAccountNo(readInt("Account number (1000-9999): "))) {
        cout << "Rejected: account number must be 1000 to 9999." << endl;
    }
}

void askBalance(BankAccount &acc) {
    while (!acc.setBalance(readDouble("Balance: "))) {
        cout << "Rejected: balance cannot be negative." << endl;
    }
}

void showAccount(BankAccount &acc) {
    cout << "\n--- Account ---" << endl;
    cout << "Owner     : " << acc.getOwner() << endl;
    cout << "Account No: " << acc.getAccountNo() << endl;
    cout << "Balance   : " << acc.getBalance() << endl;
}

int main() {
    BankAccount acc;

    cout << "Create your account" << endl;
    askOwner(acc);
    askAccountNo(acc);
    askBalance(acc);

    int choice = -1;
    while (choice != 0) {
        cout << "\n1. Show account" << endl;
        cout << "2. Change owner" << endl;
        cout << "3. Change account number" << endl;
        cout << "4. Change balance" << endl;
        cout << "0. Exit" << endl;
        choice = readInt("Choose: ");

        switch (choice) {
            case 1:
                showAccount(acc);
                break;
            case 2:
                askOwner(acc);
                cout << "Owner changed." << endl;
                break;
            case 3:
                askAccountNo(acc);
                cout << "Account number changed." << endl;
                break;
            case 4:
                askBalance(acc);
                cout << "Balance changed." << endl;
                break;
            case 0:
                cout << "Goodbye." << endl;
                break;
            default:
                cout << "Please choose 0 to 4." << endl;
        }
    }
    return 0;
}