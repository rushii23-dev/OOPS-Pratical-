# Mini Project : Expense Tracker

A simple menu-driven Expense Tracker in C++. You can add expenses, view them, see the total for each category, sort them, delete them and see a summary. All expenses are saved in `expenses.csv`, so they are still there when you run the program again.

## Features

1. Add an expense (date, category, amount, note)
2. View all expenses
3. Total spent in each category
4. Sort expenses by amount
5. Delete an expense by ID
6. Summary (count, total, average, highest)

## Concepts Used

| Concept | Where |
|---|---|
| Class and object | `ExpenseTracker` |
| Structure | `Expense` |
| Constructor | `ExpenseTracker()` loads saved data |
| Access specifiers | `list` and `nextId` are private |
| Custom exception | `InvalidInput` (child of `exception`) |
| try / catch / throw | Wrong amount, wrong ID |
| vector | Stores all expenses |
| map | Category totals |
| sort, find_if, lambda | Sort by amount, find expense to delete |
| File handling | `ofstream` to save, `ifstream` to load |
| stringstream | Splitting a CSV line |

## How to Run

```bash
g++ -std=c++17 expense_tracker.cpp -o expense_tracker
./expense_tracker
```

## Sample Output

```
----- Expense Tracker -----
1. Add Expense
2. View Expenses
3. Category Total
4. Sort by Amount
5. Delete Expense
6. Summary
0. Exit
Enter choice: 1
Date (DD-MM-YYYY): 10-11-2026
Category: Food
Amount: 120
Note: Lunch at canteen
Expense added

Enter choice: 1
Date (DD-MM-YYYY): 12-11-2026
Category: Shopping
Amount: -40
Note: Pen
Error: Amount must be more than 0

Enter choice: 2
ID	Date		Category	Amount	Note
1	10-11-2026	Food		120	Lunch at canteen
2	11-11-2026	Travel		500	Bus pass
3	12-11-2026	Food		250	Dinner with friends

Enter choice: 3
Food : 370
Travel : 500

Enter choice: 4
ID	Date		Category	Amount	Note
2	11-11-2026	Travel		500	Bus pass
3	12-11-2026	Food		250	Dinner with friends
1	10-11-2026	Food		120	Lunch at canteen

Enter choice: 5
Enter ID to delete: 2
Expense deleted

Enter choice: 6
Number of expenses: 2
Total spent: 370
Average: 185
Highest: 250

Enter choice: 0
Goodbye
```
