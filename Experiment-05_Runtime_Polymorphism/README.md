# Experiment 5

## Aim

Demonstrate runtime polymorphism using virtual functions and an abstract base class. Implement a Shape hierarchy (Circle, Rectangle, Triangle) with an area() method.

## Concepts Used

- Abstract base class `Shape`
- Pure virtual function `virtual double area() = 0;`
- Function overriding in `Circle`, `Rectangle`, `Triangle`
- Base class pointers pointing to derived class objects
- Virtual destructor
- vtable: decides at runtime which `area()` to call

## How to Compile and Run

```bash
g++ -std=c++17 shapes.cpp -o shapes
./shapes
```

## Output

```
===== Areas of Shapes (Runtime Polymorphism) =====
Circle -> Area = 78.5397
Rectangle -> Area = 24
Triangle -> Area = 12

Total area of all shapes = 114.54

===== Deleting Shapes =====
Circle destructor
Shape destructor (Circle)
Rectangle destructor
Shape destructor (Rectangle)
Triangle destructor
Shape destructor (Triangle)
```
