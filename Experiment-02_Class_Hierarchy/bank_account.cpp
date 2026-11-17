#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;
protected:
    string name;
public:
    static int count;

    BankAccount(string n, double b) {
        name = n;
        balance = b;
        count++;
    }

    void deposit(double amt);
    void withdraw(double amt);

    double getBalance() {
        return balance;
    }

    void display() {
        cout << "Name: " << name << ", Balance: " << balance << endl;
    }
};

int BankAccount::count = 0;

void BankAccount::deposit(double amt) {
    balance += amt;
    cout << "Deposited " << amt << endl;
}

void BankAccount::withdraw(double amt) {
    if (amt > balance)
        cout << "Insufficient balance" << endl;
    else {
        balance -= amt;
        cout << "Withdrawn " << amt << endl;
    }
}

class SavingsAccount : public BankAccount {
private:
    float rate;
public:
    SavingsAccount(string n, double b, float r) : BankAccount(n, b) {
        rate = r;
    }

    void addInterest() {
        double interest = getBalance() * rate / 100;
        cout << "Interest for " << name << ": " << interest << endl;
        deposit(interest);
    }
};

int main() {
    BankAccount a1("Amit", 5000);
    a1.display();
    a1.deposit(2000);
    a1.withdraw(10000);
    a1.withdraw(1000);
    a1.display();

    cout << endl;
    SavingsAccount s1("Priya", 10000, 5);
    s1.display();
    s1.addInterest();
    s1.display();

    cout << "\nTotal accounts: " << BankAccount::count << endl;
    return 0;
}
