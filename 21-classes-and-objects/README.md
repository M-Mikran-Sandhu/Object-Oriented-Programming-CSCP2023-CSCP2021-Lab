# Program 21: Classes and Objects

> Revision program written in 2026 as part of rebuilding my GitHub (Course: CSCP2023 + CSCP2021 Lab, Object Oriented Programming).

## What it does
Reads the details of two students (name, roll number, marks), stores each one in its own `Student` object, and prints both records with a Pass/Fail result. The class refuses bad data (empty name, roll number of 0 or below, marks outside 0-100), and the program asks again until the data is valid.

## Concepts used
- A **class** as a blueprint and **objects** built from it (`first`, `second`)
- `private` data members and `public` member functions (encapsulation)
- Validation inside the class (`setData` returns `false` for bad data)
- A member function that uses the object's own data (`hasPassed`, `display`)
- Input checking with `cin.fail()`, `cin.clear()` and `cin.ignore()`

## Sample run
```
--- Student 1 ---
Enter name: 
Enter roll number: 5
Enter marks (0-100): 60
Invalid data. Name must not be empty, roll number must be above 0, marks must be 0-100.

--- Student 1 ---
Enter name: Ali
Enter roll number: abc
That is not a whole number. Try again: -5
Enter marks (0-100): xyz
That is not a number. Try again: 150
Invalid data. Name must not be empty, roll number must be above 0, marks must be 0-100.

--- Student 1 ---
Enter name: Ali
Enter roll number: 12
Enter marks (0-100): 78.5

--- Student 2 ---
Enter name: Sara
Enter roll number: 7
Enter marks (0-100): 41

===== Records =====
Name   : Ali
Roll No: 12
Marks  : 78.5
Result : Pass

Name   : Sara
Roll No: 7
Marks  : 41
Result : Fail
```

## How to compile and run
```
g++ main.cpp -o main
./main
```

## What I learned
A class is a blueprint, and an object is built from it. I made two objects, `first` and `second`, from one `Student` class.

Data members are made private so outside code cannot change them directly. If `marks` was public, anyone could store a wrong value like 500 or -20.

`setData` is a public function that checks the values before storing them. It returns true if the data is valid and false if not. Checking inside the class means the rule is written once and is always followed.

`display()` prints the data of the object it is called with, so `first.display()` shows first's data and `second.display()` shows second's.

Input is checked with `cin`: if the user types letters instead of a number, `cin.clear()` and `cin.ignore()` remove the bad input and the program asks again.