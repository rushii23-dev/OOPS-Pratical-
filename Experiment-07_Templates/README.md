# Experiment 7

## Aim

Write a generic Stack class using templates. Test with int, float, and std::string.

## Concepts Used

- Class template `template <typename T> class Stack`
- Function template `showTop()`
- Stack operations: push, pop, peek, isEmpty, isFull, display
- Overflow and underflow checking
- Same code used for `int`, `float` and `string`

## How to Compile and Run

```bash
g++ -std=c++17 generic_stack.cpp -o generic_stack
./generic_stack
```

## Output

```
===== Stack of int =====
Pushed : 10
Pushed : 20
Pushed : 30
Stack (top to bottom) : 30 20 10 
Top element : 30, Size : 3
Popped : 30
Stack (top to bottom) : 20 10 

===== Stack of float =====
Pushed : 1.5
Pushed : 2.75
Pushed : 3.25
Stack (top to bottom) : 3.25 2.75 1.5 
Top element : 3.25, Size : 3
Popped : 3.25
Stack (top to bottom) : 2.75 1.5 

===== Stack of string =====
Pushed : C++
Pushed : Java
Pushed : Python
Stack (top to bottom) : Python Java C++ 
Top element : Python, Size : 3
Popped : Python
Stack (top to bottom) : Java C++ 

===== Overflow and Underflow Test =====
Pushed : 100
Pushed : 200
Pushed : 300
Pushed : 400
Pushed : 500
Stack Overflow! Cannot push 600
Popped : 500
Popped : 400
Popped : 300
Popped : 200
Popped : 100
Stack Underflow! Nothing to pop
```
