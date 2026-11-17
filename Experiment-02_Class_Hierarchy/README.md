# Experiment 2

## Aim

Design and implement a class hierarchy for a real-world entity (BankAccount). Demonstrate access specifiers and member functions.

## Concepts Used

- Class, object and constructor
- Access specifiers: `private` (balance), `protected` (name), `public` (functions)
- Member functions defined inside and outside the class (using `::`)
- Class hierarchy: `BankAccount` -> `SavingsAccount`
- Static data member (`count`)

## How to Run

```bash
g++ -std=c++17 bank_account.cpp -o bank_account
./bank_account
```

## Output

```
Name: Amit, Balance: 5000
Deposited 2000
Insufficient balance
Withdrawn 1000
Name: Amit, Balance: 6000

Name: Priya, Balance: 10000
Interest for Priya: 500
Deposited 500
Name: Priya, Balance: 10500

Total accounts: 2
```
