/*
 * Mini Project : Expense Tracker in C++
 *
 * Features:
 *   1. Add a new expense
 *   2. View all expenses
 *   3. View total spending by category
 *   4. Search expenses by category
 *   5. Sort expenses by amount
 *   6. Delete an expense
 *   7. Show summary (total, average, highest)
 *   8. Save and load expenses from a CSV file (data is kept after closing)
 *
 * Concepts used (from the syllabus):
 *   - Classes, objects, access specifiers, constructors
 *   - Static data member (to give each expense a unique ID)
 *   - Inheritance + abstract class + virtual function (Report classes)
 *   - Operator overloading (<<)
 *   - Templates (function template to find the largest value)
 *   - STL : vector, map, sort, find_if, accumulate, lambda
 *   - Custom exceptions with try / catch / throw
 *   - File handling with fstream (ios::in, ios::out)
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <exception>
#include <iomanip>
using namespace std;

const string DATA_FILE = "expenses.csv";

// =====================================================
//                 Custom Exception
// =====================================================
class InvalidInputException : public exception
{
private:
    string message;

public:
    InvalidInputException(string msg)
    {
        message = msg;
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

// =====================================================
//                 Expense class
// =====================================================
class Expense
{
private:
    int id;
    string date;          // format : DD-MM-YYYY
    string category;      // Food, Travel, Shopping, Bills ...
    string description;
    double amount;

public:
    static int nextId;    // shared by all objects, gives unique IDs

    Expense(string d, string c, string desc, double amt)
    {
        id = nextId;
        nextId++;
        date = d;
        category = c;
        description = desc;
        amount = amt;
    }

    // Constructor used when loading from file (ID already known)
    Expense(int i, string d, string c, string desc, double amt)
    {
        id = i;
        date = d;
        category = c;
        description = desc;
        amount = amt;
        if (i >= nextId)
            nextId = i + 1;
    }

    int getId() const { return id; }
    string getDate() const { return date; }
    string getCategory() const { return category; }
    string getDescription() const { return description; }
    double getAmount() const { return amount; }

    string toCSV() const
    {
        return to_string(id) + "," + date + "," + category + "," + description + "," + to_string(amount);
    }

    // Friend function to print an expense using cout <<
    friend ostream &operator<<(ostream &out, const Expense &e);
};

int Expense::nextId = 1;

ostream &operator<<(ostream &out, const Expense &e)
{
    out << left << setw(5) << e.id
        << setw(13) << e.date
        << setw(12) << e.category
        << setw(22) << e.description
        << right << setw(10) << fixed << setprecision(2) << e.amount;
    return out;
}

// =====================================================
//          Function template : largest value
// =====================================================
template <typename T>
T findMax(vector<T> values)
{
    T maxValue = values[0];
    for (T v : values)
    {
        if (v > maxValue)
            maxValue = v;
    }
    return maxValue;
}

// =====================================================
//     Abstract Report class + derived classes
// =====================================================
class Report
{
public:
    virtual void generate(const vector<Expense> &list) = 0;   // pure virtual
    virtual ~Report() {}
};

class CategoryReport : public Report
{
public:
    void generate(const vector<Expense> &list) override
    {
        map<string, double> totals;     // category -> total amount
        for (const Expense &e : list)
        {
            totals[e.getCategory()] += e.getAmount();
        }

        cout << "\n------ Spending by Category ------" << endl;
        for (auto it = totals.begin(); it != totals.end(); it++)
        {
            cout << left << setw(15) << it->first
                 << "Rs. " << fixed << setprecision(2) << it->second << endl;
        }
    }
};

class SummaryReport : public Report
{
public:
    void generate(const vector<Expense> &list) override
    {
        double total = accumulate(list.begin(), list.end(), 0.0, [](double sum, const Expense &e) {
            return sum + e.getAmount();
        });

        vector<double> amounts;
        for (const Expense &e : list)
        {
            amounts.push_back(e.getAmount());
        }

        cout << "\n------ Summary ------" << endl;
        cout << fixed << setprecision(2);
        cout << "Number of expenses : " << list.size() << endl;
        cout << "Total spent        : Rs. " << total << endl;
        cout << "Average expense    : Rs. " << total / list.size() << endl;
        cout << "Highest expense    : Rs. " << findMax(amounts) << endl;
    }
};

// =====================================================
//                ExpenseTracker class
// =====================================================
class ExpenseTracker
{
private:
    vector<Expense> expenses;

    void printHeader()
    {
        cout << left << setw(5) << "ID"
             << setw(13) << "Date"
             << setw(12) << "Category"
             << setw(22) << "Description"
             << right << setw(10) << "Amount" << endl;
        cout << string(62, '-') << endl;
    }

public:
    ExpenseTracker()
    {
        loadFromFile();
    }

    void addExpense(string date, string category, string desc, double amount)
    {
        if (amount <= 0)
            throw InvalidInputException("Amount must be greater than 0");
        if (category == "")
            throw InvalidInputException("Category cannot be empty");
        if (desc.find(',') != string::npos || category.find(',') != string::npos)
            throw InvalidInputException("Please do not use comma (,) in the text");

        Expense e(date, category, desc, amount);
        expenses.push_back(e);
        saveToFile();
        cout << "Expense added with ID " << e.getId() << endl;
    }

    void viewAll()
    {
        if (expenses.empty())
        {
            cout << "No expenses found." << endl;
            return;
        }
        printHeader();
        for (const Expense &e : expenses)
        {
            cout << e << endl;
        }
    }

    void searchByCategory(string category)
    {
        bool found = false;
        double total = 0;
        for (const Expense &e : expenses)
        {
            if (e.getCategory() == category)
            {
                if (!found)
                    printHeader();
                cout << e << endl;
                total += e.getAmount();
                found = true;
            }
        }
        if (found)
            cout << "Total for " << category << " : Rs. " << fixed << setprecision(2) << total << endl;
        else
            cout << "No expenses in category " << category << endl;
    }

    void sortByAmount()
    {
        sort(expenses.begin(), expenses.end(), [](const Expense &a, const Expense &b) {
            return a.getAmount() > b.getAmount();
        });
        cout << "Expenses sorted by amount (highest first):" << endl;
        viewAll();
    }

    void deleteExpense(int id)
    {
        auto it = find_if(expenses.begin(), expenses.end(), [id](const Expense &e) {
            return e.getId() == id;
        });
        if (it == expenses.end())
            throw InvalidInputException("No expense found with ID " + to_string(id));

        expenses.erase(it);
        saveToFile();
        cout << "Expense with ID " << id << " deleted." << endl;
    }

    void showReport(Report &report)    // works with any type of Report
    {
        if (expenses.empty())
        {
            cout << "No expenses found." << endl;
            return;
        }
        report.generate(expenses);
    }

    void saveToFile()
    {
        ofstream fout(DATA_FILE, ios::out);
        if (!fout)
        {
            cout << "Error : could not save data" << endl;
            return;
        }
        for (const Expense &e : expenses)
        {
            fout << e.toCSV() << endl;
        }
        fout.close();
    }

    void loadFromFile()
    {
        ifstream fin(DATA_FILE, ios::in);
        if (!fin)
            return;     // file not created yet, start empty

        string line;
        while (getline(fin, line))
        {
            if (line == "")
                continue;

            stringstream ss(line);
            string idStr, date, category, desc, amountStr;
            getline(ss, idStr, ',');
            getline(ss, date, ',');
            getline(ss, category, ',');
            getline(ss, desc, ',');
            getline(ss, amountStr, ',');

            Expense e(stoi(idStr), date, category, desc, stod(amountStr));
            expenses.push_back(e);
        }
        fin.close();
    }
};

// =====================================================
//              Helper input functions
// =====================================================
double readAmount()
{
    string input;
    getline(cin, input);
    try
    {
        return stod(input);
    }
    catch (...)
    {
        throw InvalidInputException("Amount must be a number");
    }
}

int readInt()
{
    string input;
    getline(cin, input);
    try
    {
        return stoi(input);
    }
    catch (...)
    {
        return -1;
    }
}

void showMenu()
{
    cout << "\n========== EXPENSE TRACKER ==========" << endl;
    cout << "1. Add Expense" << endl;
    cout << "2. View All Expenses" << endl;
    cout << "3. Spending by Category" << endl;
    cout << "4. Search by Category" << endl;
    cout << "5. Sort by Amount" << endl;
    cout << "6. Delete Expense" << endl;
    cout << "7. Summary" << endl;
    cout << "0. Exit" << endl;
    cout << "=====================================" << endl;
    cout << "Enter your choice : ";
}

// =====================================================
//                       main
// =====================================================
int main()
{
    ExpenseTracker tracker;
    CategoryReport categoryReport;
    SummaryReport summaryReport;

    int choice;
    do
    {
        showMenu();
        choice = readInt();

        try
        {
            switch (choice)
            {
            case 1:
            {
                string date, category, desc;
                cout << "Enter date (DD-MM-YYYY) : ";
                getline(cin, date);
                cout << "Enter category (Food/Travel/Shopping/Bills/Other) : ";
                getline(cin, category);
                cout << "Enter description : ";
                getline(cin, desc);
                cout << "Enter amount : ";
                double amount = readAmount();
                tracker.addExpense(date, category, desc, amount);
                break;
            }
            case 2:
                tracker.viewAll();
                break;
            case 3:
                tracker.showReport(categoryReport);
                break;
            case 4:
            {
                string category;
                cout << "Enter category to search : ";
                getline(cin, category);
                tracker.searchByCategory(category);
                break;
            }
            case 5:
                tracker.sortByAmount();
                break;
            case 6:
            {
                cout << "Enter expense ID to delete : ";
                int id = readInt();
                tracker.deleteExpense(id);
                break;
            }
            case 7:
                tracker.showReport(summaryReport);
                break;
            case 0:
                cout << "Data saved in " << DATA_FILE << ". Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        }
        catch (InvalidInputException &e)
        {
            cout << "Error : " << e.what() << endl;
        }

    } while (choice != 0 && cin);

    return 0;
}
