#include <iostream>
#include <string>
#include <cstdlib>   
using namespace std;

// ---------- The class (the blueprint) ----------
class Student {
private:                  
    string name;
    int rollNo;
    double marks;

public:                   
    
    bool setData(string n, int r, double m) {
        if (n.empty() || r <= 0 || m < 0 || m > 100) {
            return false;    
        }
        name = n;
        rollNo = r;
        marks = m;
        return true;
    }

    bool hasPassed() {
        return marks >= 50;
    }

    void display() {
        cout << "Name   : " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks  : " << marks << endl;
        cout << "Result : " << (hasPassed() ? "Pass" : "Fail") << endl;
    }
};



void stopIfInputEnded() {
    if (cin.eof()) {
        cout << "\nInput ended. Exiting." << endl;
        exit(1);
    }
}

string readName() {
    string text;
    cout << "Enter name: ";
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


Student readStudent(int number) {
    Student s;
    bool ok = false;
    while (!ok) {
        cout << "\n--- Student " << number << " ---" << endl;
        string name = readName();
        int roll = readInt("Enter roll number: ");
        double marks = readDouble("Enter marks (0-100): ");
        ok = s.setData(name, roll, marks);
        if (!ok) {
            cout << "Invalid data. Name must not be empty, "
                 << "roll number must be above 0, marks must be 0-100." << endl;
        }
    }
    return s;
}

int main() {
    Student first = readStudent(1);    // object 1
    Student second = readStudent(2);   // object 2

    cout << "\n===== Records =====" << endl;
    first.display();
    cout << endl;
    second.display();

    
    return 0;
}