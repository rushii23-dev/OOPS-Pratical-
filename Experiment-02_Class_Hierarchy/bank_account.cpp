/*
 * Experiment 2 : Class Hierarchy for a Real-World Entity (BankAccount)
 *
 * Concepts used:
 *   - Class and objects
 *   - Access specifiers : public, private, protected
 *   - Member functions (defined inside and outside the class)
 *   - Simple class hierarchy (BankAccount -> SavingsAccount, CurrentAccount)
 *   - Static data member and static member function
 *   - Array of objects
 *   - Object as a function argument
 */

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    double balance;            // private : only this class can use it

protected:
    string accountHolder;      // protected : this class and child classes
    int accountNumber;

public:
    static int totalAccounts;  // static : shared by all objects

    // Member function to set the details
    void openAccount(int accNo, string name, double amount)
    {
        accountNumber = accNo;
        accountHolder = name;
        balance = amount;
        totalAccounts++;
    }

    // Member functions declared here, defined outside the class
    void deposit(double amount);
    void withdraw(double amount);

    double getBalance()
    {
        return balance;
    }

    void display()
    {
        cout << "Account No : " << accountNumber << endl;
        cout << "Name       : " << accountHolder << endl;
        cout << "Balance    : Rs. " << balance << endl;
    }

    static void showTotalAccounts()
    {
        cout << "Total accounts opened : " << totalAccounts << endl;
    }
};

// Definition of static member
int BankAccount::totalAccounts = 0;

// Member function defined outside the class using ::
void BankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        balance = balance + amount;
        cout << "Deposited Rs. " << amount << " successfully." << endl;
    }
    else
    {
        cout << "Invalid deposit amount!" << endl;
    }
}

void BankAccount::withdraw(double amount)
{
    if (amount <= balance)
    {
        balance = balance - amount;
        cout << "Withdrawn Rs. " << amount << " successfully." << endl;
    }
    else
    {
        cout << "Insufficient balance!" << endl;
    }
}

// Child class 1
class SavingsAccount : public BankAccount
{
private:
    float interestRate;

public:
    void setInterestRate(float rate)
    {
        interestRate = rate;
    }

    void addInterest()
    {
        double interest = getBalance() * interestRate / 100;
        // accountHolder is protected, so we can use it here
        cout << "Adding interest for " << accountHolder << " : Rs. " << interest << endl;
        deposit(interest);
        // balance is private in BankAccount, so we CANNOT write: balance += interest;
    }
};

// Child class 2
class CurrentAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    void setOverdraftLimit(double limit)
    {
        overdraftLimit = limit;
    }

    void showOverdraft()
    {
        cout << "Overdraft limit for account " << accountNumber
             << " : Rs. " << overdraftLimit << endl;
    }
};

// Object passed as a function argument (by reference)
void transfer(BankAccount &from, BankAccount &to, double amount)
{
    cout << "\nTransferring Rs. " << amount << endl;
    if (from.getBalance() >= amount)
    {
        from.withdraw(amount);
        to.deposit(amount);
    }
    else
    {
        cout << "Transfer failed : insufficient balance" << endl;
    }
}

int main()
{
    cout << "===== Savings Account =====" << endl;
    SavingsAccount s1;
    s1.openAccount(1001, "Amit", 5000);
    s1.setInterestRate(4.0f);
    s1.display();
    s1.deposit(2000);
    s1.withdraw(1000);
    s1.addInterest();
    s1.display();

    cout << "\n===== Current Account =====" << endl;
    CurrentAccount c1;
    c1.openAccount(2001, "Priya", 10000);
    c1.setOverdraftLimit(5000);
    c1.display();
    c1.showOverdraft();
    c1.withdraw(20000);   // more than balance

    // Object as function argument
    transfer(c1, s1, 3000);
    cout << "\nAfter transfer:" << endl;
    s1.display();
    c1.display();

    cout << "\n===== Array of Objects =====" << endl;
    BankAccount accounts[3];
    accounts[0].openAccount(3001, "Ravi", 1500);
    accounts[1].openAccount(3002, "Sneha", 2500);
    accounts[2].openAccount(3003, "Karan", 3500);

    for (int i = 0; i < 3; i++)
    {
        accounts[i].display();
        cout << "--------------------" << endl;
    }

    BankAccount::showTotalAccounts();

    return 0;
}
