# Experiment 5

## Aim

Demonstrate runtime polymorphism using virtual functions and an abstract base class. Implement a Shape hierarchy (Circle, Rectangle, Triangle) with an area() method.

## Concepts Used

- Abstract base class `Shape`
- Pure virtual functions `area()` and `display()`
- Function overriding using `override`
- Base class pointers pointing to child class objects
- Virtual destructor

## How to Run

```bash
g++ -std=c++17 shapes.cpp -o shapes
./shapes
```

## Output

```
Circle area: 78.5
Rectangle area: 24
Triangle area: 12
```
