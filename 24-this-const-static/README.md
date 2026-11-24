# Program 24: this pointer, const member functions, static members

## Objective
Show how a class can keep a shared counter of its objects (`static`), use `this` to tell its own members from constructor parameters, and mark read-only functions `const`.

## Concepts demonstrated
- `this` pointer and `this->`
- `const` member functions and a `const` object
- Passing an object by `const` reference
- `static` data member and `static` member function
- Constructor and destructor keeping a shared counter

## Language and requirements
C++, compiled with `g++`. No extra libraries.

## How to run
```
g++ main.cpp -o main
./main
```

## Sample run
```
Students at start: 0

--- First student ---
Enter name: Ali Khan
Enter roll number: 12
Enter marks (0-100): 78.5

--- Second student ---
Enter name: Sara
Enter roll number: 7
Enter marks (0-100): 41

Students now: 2

New marks for the first student: -5
Rejected. Marks must be 0-100. Try again: 90
Card of Ali Khan:
  Ali Khan | Roll 12 | Marks 90

a is the same object as a? yes
a is the same object as b? no
  Fixed | Roll 100 | Marks 90

Students now: 3
Inside the block: 4
After the block: 3
```

## Notes
- Invalid values given to the constructor are replaced with safe ones, because a constructor cannot return an error.
- Calling `fixed.setMarks(50)` on the `const` object does not compile, because `setMarks` is not a `const` function.
- If the input ends early, the program exits with code 1.

## What I learned
`this` is a pointer to the object that called the function. I use `this->name = name;` when the parameter has the same name as the member.

A `const` after a member function means it will not change the object. Only const functions can be called on a const object.

A static member is shared by all objects of the class. There is only one copy. I used it to count how many students exist.

A static data member is defined once outside the class, and a static function is called with the class name, like `Student::getCount()`.