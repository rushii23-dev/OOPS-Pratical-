# Mini Project : Expense Tracker

A menu-driven Expense Tracker written in C++. You can add your daily expenses, see them, find the total spent in each category, search, sort, delete, and get a summary. All expenses are saved in a file (`expenses.csv`), so the data is still there the next time you run the program.

## Features

1. Add an expense (date, category, description, amount)
2. View all expenses in a table
3. See total spending for each category
4. Search expenses by category
5. Sort expenses by amount (highest first)
6. Delete an expense using its ID
7. Summary: number of expenses, total, average and highest expense
8. Data is saved to and loaded from `expenses.csv` automatically

## Syllabus Concepts Used

| Concept | Where it is used |
|---|---|
| Classes, objects, access specifiers | `Expense`, `ExpenseTracker` classes |
| Constructors (overloaded) | `Expense` has two constructors |
| Static data member | `Expense::nextId` gives every expense a unique ID |
| Inheritance and abstract class | `Report` (abstract) -> `CategoryReport`, `SummaryReport` |
| Runtime polymorphism (virtual functions) | `showReport(Report &report)` calls `generate()` |
| Operator overloading | `<<` overloaded to print an `Expense` |
| Friend function | `operator<<` is a friend of `Expense` |
| Function template | `findMax()` finds the highest amount |
| STL containers | `vector<Expense>`, `map<string, double>` |
| STL algorithms and lambdas | `sort`, `find_if`, `accumulate` |
| Custom exception | `InvalidInputException` for wrong input |
| try / catch / throw | Adding and deleting expenses |
| File handling | `ofstream` / `ifstream` with `ios::out` and `ios::in` |

## How to Compile and Run

```bash
g++ -std=c++17 expense_tracker.cpp -o expense_tracker
./expense_tracker
```

## Sample Run

```
========== EXPENSE TRACKER ==========
1. Add Expense
2. View All Expenses
3. Spending by Category
4. Search by Category
5. Sort by Amount
6. Delete Expense
7. Summary
0. Exit
=====================================
Enter your choice : 1
Enter date (DD-MM-YYYY) : 10-11-2026
Enter category (Food/Travel/Shopping/Bills/Other) : Food
Enter description : Lunch at canteen
Enter amount : 120
Expense added with ID 1

Enter your choice : 1
Enter date (DD-MM-YYYY) : 12-11-2026
Enter category (Food/Travel/Shopping/Bills/Other) : Shopping
Enter description : Notebook
Enter amount : -40
Error : Amount must be greater than 0

Enter your choice : 2
ID   Date         Category    Description               Amount
--------------------------------------------------------------
1    10-11-2026   Food        Lunch at canteen          120.00
2    11-11-2026   Travel      Bus pass                  500.00
3    12-11-2026   Food        Dinner                    250.00

Enter your choice : 3

------ Spending by Category ------
Food           Rs. 370.00
Travel         Rs. 500.00

Enter your choice : 4
Enter category to search : Food
ID   Date         Category    Description               Amount
--------------------------------------------------------------
1    10-11-2026   Food        Lunch at canteen          120.00
3    12-11-2026   Food        Dinner                    250.00
Total for Food : Rs. 370.00

Enter your choice : 5
Expenses sorted by amount (highest first):
ID   Date         Category    Description               Amount
--------------------------------------------------------------
2    11-11-2026   Travel      Bus pass                  500.00
3    12-11-2026   Food        Dinner                    250.00
1    10-11-2026   Food        Lunch at canteen          120.00

Enter your choice : 6
Enter expense ID to delete : 2
Expense with ID 2 deleted.

Enter your choice : 7

------ Summary ------
Number of expenses : 2
Total spent        : Rs. 370.00
Average expense    : Rs. 185.00
Highest expense    : Rs. 250.00

Enter your choice : 0
Data saved in expenses.csv. Goodbye!
```

(The menu is printed before every choice; it is shown only once above to keep it short.)
