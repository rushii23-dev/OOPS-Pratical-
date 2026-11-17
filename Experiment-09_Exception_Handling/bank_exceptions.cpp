#include <iostream>
#include <string>
using namespace std;

class BankException : public exception {
protected:
    string msg;
public:
    BankException(string m) {
        msg = m;
    }
    const char *what() const noexcept override {
        return msg.c_str();
    }
};

class InvalidAmount : public BankException {
public:
    InvalidAmount() : BankException("Amount must be positive") {}
};

class InsufficientBalance : public BankException {
public:
    InsufficientBalance() : BankException("Not enough balance") {}
};

class Account {
private:
    double balance;
public:
    Account(double b) {
        balance = b;
    }

    double getBalance() const noexcept {
        return balance;
    }

    void deposit(double amt) {
        if (amt <= 0)
            throw InvalidAmount();
        balance += amt;
        cout << "Deposited " << amt << ", Balance: " << balance << endl;
    }

    void withdraw(double amt) {
        if (amt <= 0)
            throw InvalidAmount();
        if (amt > balance)
            throw InsufficientBalance();
        balance -= amt;
        cout << "Withdrawn " << amt << ", Balance: " << balance << endl;
    }
};

int main() {
    Account acc(5000);

    try {
        acc.deposit(1000);
        acc.withdraw(2000);
    }
    catch (BankException &e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        acc.deposit(-500);
    }
    catch (InvalidAmount &e) {
        cout << "InvalidAmount caught: " << e.what() << endl;
    }

    try {
        acc.withdraw(10000);
    }
    catch (InvalidAmount &e) {
        cout << "InvalidAmount caught: " << e.what() << endl;
    }
    catch (InsufficientBalance &e) {
        cout << "InsufficientBalance caught: " << e.what() << endl;
    }

    try {
        throw 404;
    }
    catch (BankException &e) {
        cout << "Bank error: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown error caught" << endl;
    }

    cout << "Final balance: " << acc.getBalance() << endl;
    return 0;
}
