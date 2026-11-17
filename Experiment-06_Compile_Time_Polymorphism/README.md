# Experiment 6

## Aim

Implement compile-time polymorphism: function overloading and operator overloading for a Complex Number class.

## Concepts Used

- Function overloading: `add(int,int)`, `add(double,double)`, `add(int,int,int)`
- Constructor overloading
- Operator overloading: `+`, `-`, `*`, `==`
- Friend function to overload `<<`

## How to Compile and Run

```bash
g++ -std=c++17 complex_number.cpp -o complex_number
./complex_number
```

## Output

```
===== Function Overloading =====
add(10, 20)       = 30
add(2.5, 3.5)     = 6
add(1, 2, 3)      = 6

===== Operator Overloading (Complex Numbers) =====
c1 = 3 + 4i
c2 = 1 - 2i
c3 = 0 + 0i  (default constructor)

c1 + c2 = 4 + 2i
c1 - c2 = 2 + 6i
c1 * c2 = 11 - 2i

c4 = 3 + 4i
c1 and c4 are equal
c1 and c2 are not equal
```
