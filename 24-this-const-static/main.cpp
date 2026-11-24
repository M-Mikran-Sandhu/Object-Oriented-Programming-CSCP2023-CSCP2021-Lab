#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    double marks;
    static int count;        

public:
    
    Student(string name, int rollNo, double marks) {
        if (name.empty()) {
            name = "Unknown";
        }
        if (rollNo <= 0) {
            rollNo = 1;
        }
        if (marks < 0 || marks > 100) {
            marks = 0;
        }
        this->name = name;
        this->rollNo = rollNo;
        this->marks = marks;
        count++;             
    }

    ~Student() {
        count--;             
    }

    
    bool setMarks(double marks) {
        if (marks < 0 || marks > 100) {
            return false;
        }
        this->marks = marks;
        return true;
    }

    string getName() const {
        return name;
    }

    void display() const {
        cout << "  " << name << " | Roll " << rollNo << " | Marks " << marks << endl;
    }

    bool isSameObject(const Student &other) const {
        return this == &other;
    }

    static int getCount() {
        return count;
    }
};


int Student::count = 0;


void showCard(const Student &s) {
    cout << "Card of " << s.getName() << ":" << endl;
    s.display();
}


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
    cout << "Students at start: " << Student::getCount() << endl;

    cout << "\n--- First student ---" << endl;
    string n1 = readText("Enter name: ");
    int r1 = readInt("Enter roll number: ");
    double m1 = readDouble("Enter marks (0-100): ");
    Student a(n1, r1, m1);

    cout << "\n--- Second student ---" << endl;
    string n2 = readText("Enter name: ");
    int r2 = readInt("Enter roll number: ");
    double m2 = readDouble("Enter marks (0-100): ");
    Student b(n2, r2, m2);

    cout << "\nStudents now: " << Student::getCount() << endl;

    
    double newMarks = readDouble("\nNew marks for the first student: ");
    while (!a.setMarks(newMarks)) {
        newMarks = readDouble("Rejected. Marks must be 0-100. Try again: ");
    }
    showCard(a);

    
    cout << "\na is the same object as a? "
         << (a.isSameObject(a) ? "yes" : "no") << endl;
    cout << "a is the same object as b? "
         << (a.isSameObject(b) ? "yes" : "no") << endl;

    
    const Student fixed("Fixed", 100, 90);
    fixed.display();
    

    cout << "\nStudents now: " << Student::getCount() << endl;
    {
        Student temp("Temp", 99, 60);
        cout << "Inside the block: " << Student::getCount() << endl;
    }
    cout << "After the block: " << Student::getCount() << endl;

    return 0;
}