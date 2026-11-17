# Experiment 9

## Aim

Create a custom exception hierarchy. Write a program that throws and catches specific exceptions for a banking transaction scenario.

## Concepts Used

- `try`, `catch`, `throw`
- Custom exceptions derived from `std::exception`: `BankException` -> `InvalidAmountException`, `InsufficientFundsException`, `AccountNotFoundException`
- Catching specific exceptions first and the base class last
- `catch(...)` to catch all types of exceptions
- `noexcept` specifier
- Strong exception guarantee (balance does not change when withdraw fails)

## How to Compile and Run

```bash
g++ -std=c++17 bank_exceptions.cpp -o bank_exceptions
./bank_exceptions
```

## Output

```
===== Test 1 : Valid deposit =====
Deposited 2000. New balance : 7000

===== Test 2 : Negative deposit =====
InvalidAmountException caught -> Invalid amount : -500.000000 (amount must be positive)

===== Test 3 : Withdraw more than balance =====
InsufficientFundsException caught -> Insufficient funds : balance is 1000.000000 but tried to withdraw 5000.000000
Balance is still : 1000

===== Test 4 : Account that does not exist =====
AccountNotFoundException caught -> Account not found : 9999

===== Test 5 : Many catch blocks (specific first, base last) =====
Insufficient funds -> Insufficient funds : balance is 3000.000000 but tried to withdraw 10000.000000

===== Test 6 : Successful transfer =====
Withdrawn 1500. New balance : 5500
Deposited 1500. New balance : 2500
Transfer of 1500 from 1001 to 1003 done.

===== Test 7 : catch(...) catches anything =====
Unknown exception caught by catch(...)

===== Final Balances =====
1001 : 5500
1002 : 3000
1003 : 2500
```
