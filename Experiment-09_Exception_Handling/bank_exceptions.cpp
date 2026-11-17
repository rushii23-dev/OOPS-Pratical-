/*
 * Experiment 9 : Custom Exception Hierarchy for a Banking Transaction
 *
 * Concepts used:
 *   - try, catch, throw
 *   - Custom exception classes derived from std::exception
 *   - Exception hierarchy:
 *         std::exception
 *              |
 *         BankException
 *          /         |            \
 *   InvalidAmount  InsufficientFunds  AccountNotFound
 *   - Catching specific exceptions first, then the base class
 *   - catch(...) to catch all types of exceptions
 *   - noexcept specifier
 *   - Strong exception guarantee : if withdraw fails, balance does not change
 */

#include <iostream>
#include <string>
#include <exception>
using namespace std;

// ---------- Base exception class ----------
class BankException : public exception
{
protected:
    string message;

public:
    BankException(string msg)
    {
        message = msg;
    }

    // what() gives the error message
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

// ---------- Derived exception classes ----------
class InvalidAmountException : public BankException
{
public:
    InvalidAmountException(double amount)
        : BankException("Invalid amount : " + to_string(amount) + " (amount must be positive)")
    {
    }
};

class InsufficientFundsException : public BankException
{
public:
    InsufficientFundsException(double balance, double amount)
        : BankException("Insufficient funds : balance is " + to_string(balance) +
                        " but tried to withdraw " + to_string(amount))
    {
    }
};

class AccountNotFoundException : public BankException
{
public:
    AccountNotFoundException(int accNo)
        : BankException("Account not found : " + to_string(accNo))
    {
    }
};

// ---------- Account class ----------
class Account
{
private:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    // noexcept : this function will never throw
    int getAccountNumber() const noexcept
    {
        return accountNumber;
    }

    double getBalance() const noexcept
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException(amount);
        balance = balance + amount;
        cout << "Deposited " << amount << ". New balance : " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmountException(amount);
        if (amount > balance)
            throw InsufficientFundsException(balance, amount);
        balance = balance - amount;   // changed only when everything is OK
        cout << "Withdrawn " << amount << ". New balance : " << balance << endl;
    }
};

// ---------- Simple bank with 3 accounts ----------
Account accounts[3] = {
    Account(1001, "Amit", 5000),
    Account(1002, "Sara", 3000),
    Account(1003, "Raj", 1000)
};

Account &findAccount(int accNo)
{
    for (int i = 0; i < 3; i++)
    {
        if (accounts[i].getAccountNumber() == accNo)
            return accounts[i];
    }
    throw AccountNotFoundException(accNo);
}

void transfer(int fromAcc, int toAcc, double amount)
{
    Account &from = findAccount(fromAcc);
    Account &to = findAccount(toAcc);
    from.withdraw(amount);
    to.deposit(amount);
    cout << "Transfer of " << amount << " from " << fromAcc << " to " << toAcc << " done." << endl;
}

int main()
{
    cout << "===== Test 1 : Valid deposit =====" << endl;
    try
    {
        findAccount(1001).deposit(2000);
    }
    catch (BankException &e)
    {
        cout << "Error : " << e.what() << endl;
    }

    cout << "\n===== Test 2 : Negative deposit =====" << endl;
    try
    {
        findAccount(1002).deposit(-500);
    }
    catch (InvalidAmountException &e)
    {
        cout << "InvalidAmountException caught -> " << e.what() << endl;
    }

    cout << "\n===== Test 3 : Withdraw more than balance =====" << endl;
    try
    {
        findAccount(1003).withdraw(5000);
    }
    catch (InsufficientFundsException &e)
    {
        cout << "InsufficientFundsException caught -> " << e.what() << endl;
        cout << "Balance is still : " << findAccount(1003).getBalance() << endl;
    }

    cout << "\n===== Test 4 : Account that does not exist =====" << endl;
    try
    {
        findAccount(9999).deposit(100);
    }
    catch (AccountNotFoundException &e)
    {
        cout << "AccountNotFoundException caught -> " << e.what() << endl;
    }

    cout << "\n===== Test 5 : Many catch blocks (specific first, base last) =====" << endl;
    try
    {
        transfer(1002, 1001, 10000);
    }
    catch (InvalidAmountException &e)
    {
        cout << "Invalid amount -> " << e.what() << endl;
    }
    catch (InsufficientFundsException &e)
    {
        cout << "Insufficient funds -> " << e.what() << endl;
    }
    catch (BankException &e)
    {
        cout << "Some bank error -> " << e.what() << endl;
    }

    cout << "\n===== Test 6 : Successful transfer =====" << endl;
    try
    {
        transfer(1001, 1003, 1500);
    }
    catch (BankException &e)
    {
        cout << "Error : " << e.what() << endl;
    }

    cout << "\n===== Test 7 : catch(...) catches anything =====" << endl;
    try
    {
        throw 404;    // throwing an int, not a class
    }
    catch (BankException &e)
    {
        cout << "Bank error : " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown exception caught by catch(...)" << endl;
    }

    cout << "\n===== Final Balances =====" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << accounts[i].getAccountNumber() << " : " << accounts[i].getBalance() << endl;
    }

    return 0;
}
