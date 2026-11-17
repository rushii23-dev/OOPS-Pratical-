# Experiment 1

## Aim

Set up a GitHub repository. Write a C++ program to demonstrate data types, constants, variables, operators, and I/O. Commit with a meaningful message.

## Concepts Used

- Data types: `int`, `float`, `double`, `char`, `bool`, `string`
- Constants using `const` and `constexpr`
- Variables and the `auto` keyword
- Arithmetic, relational, logical, assignment and increment operators
- Scope resolution operator `::`
- `new`, `delete` and `nullptr`
- Range-based `for` loop
- Input and output using `cin` and `cout`

## How to Run

```bash
g++ -std=c++17 basics.cpp -o basics
./basics
```

## Output

Input given: `15 4`

```
Name: Rahul
Age: 19
Height: 5.8
Salary: 25000.8
Grade: A
Pass: 1
PI: 3.14, Days: 7, Marks: 85
Size of int: 4, double: 8, char: 1

Enter two numbers: 15 4
a + b = 19
a - b = 11
a * b = 60
a / b = 3
a % b = 3
a > b : 1
a == b : 0
a > 0 && b > 0 : 1
a > 0 || b > 0 : 1
a += 5 : 20
a++ : 21

Local num: 50, Global num: 100
Value using new: 500
Array: 10 20 30 40 50
```
