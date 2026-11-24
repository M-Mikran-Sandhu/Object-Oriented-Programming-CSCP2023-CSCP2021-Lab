# Program 23: Constructors and Destructors

> Revision program written in 2026 as part of rebuilding my GitHub (Course: CSCP2023 + CSCP2021 Lab, Object Oriented Programming).

## What it does
A `Student` class that sets itself up with a constructor and prints a message from its destructor. The program creates a default student, a student from user input, and a temporary student inside a small block, so the order of creation and destruction is visible on screen. Bad values passed to the constructor are replaced with safe ones.

## Concepts used
- Default constructor and parameterized constructor
- Destructor (`~Student`)
- When objects are created and destroyed (block scope, end of `main`)
- Destruction in reverse order of creation
- Replacing invalid values inside a constructor
- Input checking with `while (!(cin >> value))`, `cin.clear()` and `cin.ignore()`

## Sample run
```
main starts
[Created  ] default student Unknown
  Unknown | Roll 1 | Marks 0
Enter name: Ali Khan
Enter roll number: 12
Enter marks (0-100): 78.5
[Created  ] student Ali Khan
  Ali Khan | Roll 12 | Marks 78.5

Entering a small block
[Created  ] student Temp
  Temp | Roll 99 | Marks 60
[Destroyed] student Temp
Left the block

main ends
[Destroyed] student Ali Khan
[Destroyed] student Unknown
```

## How to compile and run
```
g++ main.cpp -o main
./main
```

## What I learned
A constructor has the same name as the class and no return type. It runs automatically when an object is created and gives every member a starting value.

A class can have more than one constructor. The default one has no parameters, and the parameterized one takes values.

A constructor cannot return true or false, so it replaces bad values with safe ones.

A destructor has a `~` before the class name. It runs automatically when the object is destroyed.

An object is destroyed at the end of the block where it was made. Objects in `main` are destroyed in reverse order, last created first.