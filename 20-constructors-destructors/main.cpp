#include <iostream>
#include <string>
#include <cstdlib>   
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    double marks;

public:
    
    Student() {
        name = "Unknown";
        rollNo = 1;
        marks = 0;
        cout << "[Created  ] default student " << name << endl;
    }

    
    Student(string n, int r, double m) {
        if (n.empty()) {
            n = "Unknown";
        }
        if (r <= 0) {
            r = 1;
        }
        if (m < 0 || m > 100) {
            m = 0;
        }
        name = n;
        rollNo = r;
        marks = m;
        cout << "[Created  ] student " << name << endl;
    }

    
    ~Student() {
        cout << "[Destroyed] student " << name << endl;
    }

    void display() {
        cout << "  " << name << " | Roll " << rollNo
             << " | Marks " << marks << endl;
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

int main() {
    cout << "main starts" << endl;

    Student a;                       
    a.display();

    string name = readText("Enter name: ");
    int roll = readInt("Enter roll number: ");
    double marks = readDouble("Enter marks (0-100): ");
    Student b(name, roll, marks);   
    b.display();

    cout << "\nEntering a small block" << endl;
    {
        Student temp("Temp", 99, 60);    
        temp.display();
    }                                    
    cout << "Left the block" << endl;

    cout << "\nmain ends" << endl;
    return 0;                           
}