# Experiment 9

## Aim

Create a custom exception hierarchy. Write a program that throws and catches specific exceptions for a banking transaction scenario.

## Concepts Used

- `try`, `catch`, `throw`
- Custom exceptions: `BankException` -> `InvalidAmount`, `InsufficientBalance`
- Many catch blocks for specific exceptions
- `catch(...)` to catch any exception
- `noexcept`

## How to Run

```bash
g++ -std=c++17 bank_exceptions.cpp -o bank_exceptions
./bank_exceptions
```

## Output

```
Deposited 1000, Balance: 6000
Withdrawn 2000, Balance: 4000
InvalidAmount caught: Amount must be positive
InsufficientBalance caught: Not enough balance
Unknown error caught
Final balance: 4000
```
