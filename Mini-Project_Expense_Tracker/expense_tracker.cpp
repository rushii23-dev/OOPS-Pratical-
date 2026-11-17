#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class InvalidInput : public exception {
    string msg;
public:
    InvalidInput(string m) {
        msg = m;
    }
    const char *what() const noexcept override {
        return msg.c_str();
    }
};

struct Expense {
    int id;
    string date, category;
    double amount;
    string note;
};

class ExpenseTracker {
private:
    vector<Expense> list;
    int nextId = 1;

public:
    ExpenseTracker() {
        load();
    }

    void add(string date, string category, double amount, string note) {
        if (amount <= 0)
            throw InvalidInput("Amount must be more than 0");
        list.push_back({nextId, date, category, amount, note});
        nextId++;
        save();
        cout << "Expense added" << endl;
    }

    void show() {
        if (list.empty()) {
            cout << "No expenses" << endl;
            return;
        }
        cout << "ID\tDate\t\tCategory\tAmount\tNote" << endl;
        for (Expense e : list)
            cout << e.id << "\t" << e.date << "\t" << e.category << "\t\t" << e.amount << "\t" << e.note << endl;
    }

    void categoryTotal() {
        map<string, double> total;
        for (Expense e : list)
            total[e.category] += e.amount;
        for (auto p : total)
            cout << p.first << " : " << p.second << endl;
    }

    void sortByAmount() {
        sort(list.begin(), list.end(), [](Expense a, Expense b) { return a.amount > b.amount; });
        show();
    }

    void remove(int id) {
        auto it = find_if(list.begin(), list.end(), [id](Expense e) { return e.id == id; });
        if (it == list.end())
            throw InvalidInput("No expense with this ID");
        list.erase(it);
        save();
        cout << "Expense deleted" << endl;
    }

    void summary() {
        if (list.empty()) {
            cout << "No expenses" << endl;
            return;
        }
        double total = 0, highest = 0;
        for (Expense e : list) {
            total += e.amount;
            if (e.amount > highest)
                highest = e.amount;
        }
        cout << "Number of expenses: " << list.size() << endl;
        cout << "Total spent: " << total << endl;
        cout << "Average: " << total / list.size() << endl;
        cout << "Highest: " << highest << endl;
    }

    void save() {
        ofstream fout("expenses.csv");
        for (Expense e : list)
            fout << e.id << "," << e.date << "," << e.category << "," << e.amount << "," << e.note << endl;
        fout.close();
    }

    void load() {
        ifstream fin("expenses.csv");
        string line;
        while (getline(fin, line)) {
            if (line == "")
                continue;
            stringstream ss(line);
            Expense e;
            string id, amount;
            getline(ss, id, ',');
            getline(ss, e.date, ',');
            getline(ss, e.category, ',');
            getline(ss, amount, ',');
            getline(ss, e.note);
            e.id = stoi(id);
            e.amount = stod(amount);
            list.push_back(e);
            if (e.id >= nextId)
                nextId = e.id + 1;
        }
        fin.close();
    }
};

int main() {
    ExpenseTracker t;
    int choice;

    do {
        cout << "\n----- Expense Tracker -----" << endl;
        cout << "1. Add Expense" << endl;
        cout << "2. View Expenses" << endl;
        cout << "3. Category Total" << endl;
        cout << "4. Sort by Amount" << endl;
        cout << "5. Delete Expense" << endl;
        cout << "6. Summary" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (!cin)
            break;

        try {
            if (choice == 1) {
                string date, category, note;
                double amount;
                cout << "Date (DD-MM-YYYY): ";
                cin >> date;
                cout << "Category: ";
                cin >> category;
                cout << "Amount: ";
                cin >> amount;
                if (!cin) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw InvalidInput("Amount must be a number");
                }
                cout << "Note: ";
                cin.ignore();
                getline(cin, note);
                t.add(date, category, amount, note);
            }
            else if (choice == 2)
                t.show();
            else if (choice == 3)
                t.categoryTotal();
            else if (choice == 4)
                t.sortByAmount();
            else if (choice == 5) {
                int id = 0;
                cout << "Enter ID to delete: ";
                cin >> id;
                t.remove(id);
            }
            else if (choice == 6)
                t.summary();
            else if (choice != 0)
                cout << "Invalid choice" << endl;
        }
        catch (InvalidInput &e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 0);

    cout << "Goodbye" << endl;
    return 0;
}
