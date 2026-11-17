# Experiment 1

## Aim

Set up a GitHub repository. Write a C++ program to demonstrate data types, constants, variables, operators, and I/O. Commit with a meaningful message.

## Concepts Used

- Basic data types: `int`, `float`, `double`, `char`, `bool`, `string`
- Constants using `const` and `constexpr`
- Variables and the `auto` keyword
- Arithmetic, relational, logical, assignment and increment/decrement operators
- Scope resolution operator `::`
- Memory management operators `new` / `delete` and `nullptr`
- Range-based `for` loop
- Console input/output with `cin` and `cout`

## How to Compile and Run

```bash
g++ -std=c++17 basics.cpp -o basics
./basics
```

## Output

Input given: first number = `15`, second number = `4`

```
===== 1. Data Types and Variables =====
Name       : Rahul
Age        : 19
Height     : 5.8
Salary     : 25000.8
Grade      : A
Is Student : 1

Size of int    : 4 bytes
Size of float  : 4 bytes
Size of double : 8 bytes
Size of char   : 1 bytes
Size of bool   : 1 bytes

===== 2. Constants =====
Days in a week : 7
Value of PI    : 3.14159

===== 3. auto keyword =====
marks = 85, percent = 85.5, letter = B

===== 4. Input from user =====
Enter first number  : 15
Enter second number : 4
===== 5. Arithmetic Operators =====
15 + 4 = 19
15 - 4 = 11
15 * 4 = 60
15 / 4 = 3
15 % 4 = 3

===== 6. Relational Operators =====
a == b : 0
a != b : 1
a > b  : 1
a < b  : 0
a >= b : 1
a <= b : 0

===== 7. Logical Operators =====
(a > 0 && b > 0) : 1
(a > 0 || b > 0) : 1
!(a > 0)         : 0

===== 8. Assignment and Increment Operators =====
x = 10
x += 5  -> 15
x -= 3  -> 12
x *= 2  -> 24
x /= 4  -> 6
x++     -> 7
x--     -> 6

===== 9. Scope Resolution Operator (::) =====
Local number  : 50
Global number : 100

===== 10. new and delete (Memory Management) =====
Value stored in dynamic memory : 500
Dynamic array : 10 20 30 40 50 

===== 11. Range-based for loop =====
Scores : 70 80 90 60 75
```
