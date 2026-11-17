# Experiment 7

## Aim

Write a generic Stack class using templates. Test with int, float, and std::string.

## Concepts Used

- Class template `template <typename T> class Stack`
- Stack operations: push, pop, display
- Stack full and stack empty checks
- The same class used for `int`, `float` and `string`

## How to Run

```bash
g++ -std=c++17 generic_stack.cpp -o generic_stack
./generic_stack
```

## Output

```
Int stack: 30 20 10 
Popped: 30

Float stack: 2.5 1.5 
Popped: 2.5

String stack: Python Java C++ 
Popped: Python

Overflow test
Stack is full
```
