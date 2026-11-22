# Program 19: Getters and Setters with Validation

> Revision program written in 2026 as part of rebuilding my GitHub (Course: CSCP2023 + CSCP2021 Lab, Object Oriented Programming).

## What it does
A small bank account program. It creates one account (owner, 4-digit account number, balance) and shows a menu to view the account or change any value. Setters reject bad values (empty name, account number outside 1000-9999, negative balance) and the program asks again.

## Concepts used
- Setters that validate and return `true` or `false`
- Getters that only read private data
- Private data members with a public interface
- Passing an object by reference (`BankAccount &acc`)
- A menu with `while` and `switch`
- Input checking with `while (!(cin >> value))`, `cin.clear()` and `cin.ignore()`

## Sample run
```
Create your account
Owner name: 
Rejected: name must not be empty.
Owner name: Ali Khan
Account number (1000-9999): abc
That is not a whole number. Try again: 99
Rejected: account number must be 1000 to 9999.
Account number (1000-9999): 1234
Balance: -50
Rejected: balance cannot be negative.
Balance: 500.75
Choose: 4
Balance: -10
Rejected: balance cannot be negative.
Balance: 900
Balance changed.
Choose: 3
Account number (1000-9999): 10000
Rejected: account number must be 1000 to 9999.
Account number (1000-9999): 4321
Account number changed.
Choose: 1

--- Account ---
Owner     : Ali Khan
Account No: 4321
Balance   : 900
Choose: 0
Goodbye.
```
(The menu list is shortened here. It prints before every "Choose:".)

## How to compile and run
```
g++ main.cpp -o main
./main
```

## What I learned
A setter is a public function that checks a value before storing it. If the value is bad it returns false and the old value stays.

A getter only reads a private value and returns it. It does not change anything.

Setters and getters let outside code use private data safely. The class keeps control of its own data.

`BankAccount &acc` passes the real object to a function. Without `&` the function would change only a copy.