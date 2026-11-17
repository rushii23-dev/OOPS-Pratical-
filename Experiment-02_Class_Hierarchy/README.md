# Experiment 2

## Aim

Design and implement a class hierarchy for a real-world entity (BankAccount). Demonstrate access specifiers and member functions.

## Concepts Used

- Class and objects
- Access specifiers: `private` (balance), `protected` (name, account number), `public` (functions)
- Member functions defined inside and outside the class (using `::`)
- Class hierarchy: `BankAccount` -> `SavingsAccount`, `CurrentAccount`
- Static data member and static member function
- Array of objects
- Object passed as a function argument

## How to Compile and Run

```bash
g++ -std=c++17 bank_account.cpp -o bank_account
./bank_account
```

## Output

```
===== Savings Account =====
Account No : 1001
Name       : Amit
Balance    : Rs. 5000
Deposited Rs. 2000 successfully.
Withdrawn Rs. 1000 successfully.
Adding interest for Amit : Rs. 240
Deposited Rs. 240 successfully.
Account No : 1001
Name       : Amit
Balance    : Rs. 6240

===== Current Account =====
Account No : 2001
Name       : Priya
Balance    : Rs. 10000
Overdraft limit for account 2001 : Rs. 5000
Insufficient balance!

Transferring Rs. 3000
Withdrawn Rs. 3000 successfully.
Deposited Rs. 3000 successfully.

After transfer:
Account No : 1001
Name       : Amit
Balance    : Rs. 9240
Account No : 2001
Name       : Priya
Balance    : Rs. 7000

===== Array of Objects =====
Account No : 3001
Name       : Ravi
Balance    : Rs. 1500
--------------------
Account No : 3002
Name       : Sneha
Balance    : Rs. 2500
--------------------
Account No : 3003
Name       : Karan
Balance    : Rs. 3500
--------------------
Total accounts opened : 5
```
