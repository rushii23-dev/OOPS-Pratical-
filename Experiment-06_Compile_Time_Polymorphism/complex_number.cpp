/*
 * Experiment 6 : Compile-time Polymorphism
 *                Function Overloading and Operator Overloading (Complex Number)
 *
 * Concepts used:
 *   - Function overloading : same function name, different parameters
 *   - Constructor overloading
 *   - Operator overloading : +, -, *, == as member functions
 *   - Friend function to overload << (for cout)
 *   - The compiler decides which function to call at compile time
 */

#include <iostream>
using namespace std;

// ---------- Part 1 : Function Overloading ----------

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

// ---------- Part 2 : Operator Overloading ----------

class Complex
{
private:
    double real;
    double imag;

public:
    // Constructor overloading
    Complex()
    {
        real = 0;
        imag = 0;
    }

    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    // Overload + operator
    Complex operator+(const Complex &c)
    {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    // Overload - operator
    Complex operator-(const Complex &c)
    {
        Complex result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }

    // Overload * operator
    // (a + bi) * (c + di) = (ac - bd) + (ad + bc)i
    Complex operator*(const Complex &c)
    {
        Complex result;
        result.real = real * c.real - imag * c.imag;
        result.imag = real * c.imag + imag * c.real;
        return result;
    }

    // Overload == operator
    bool operator==(const Complex &c)
    {
        return (real == c.real && imag == c.imag);
    }

    // Friend function to overload << operator
    friend ostream &operator<<(ostream &out, const Complex &c);
};

ostream &operator<<(ostream &out, const Complex &c)
{
    if (c.imag >= 0)
        out << c.real << " + " << c.imag << "i";
    else
        out << c.real << " - " << -c.imag << "i";
    return out;
}

int main()
{
    cout << "===== Function Overloading =====" << endl;
    cout << "add(10, 20)       = " << add(10, 20) << endl;
    cout << "add(2.5, 3.5)     = " << add(2.5, 3.5) << endl;
    cout << "add(1, 2, 3)      = " << add(1, 2, 3) << endl;

    cout << "\n===== Operator Overloading (Complex Numbers) =====" << endl;
    Complex c1(3, 4);
    Complex c2(1, -2);
    Complex c3;

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << "  (default constructor)" << endl;

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "\nc1 + c2 = " << sum << endl;
    cout << "c1 - c2 = " << diff << endl;
    cout << "c1 * c2 = " << prod << endl;

    Complex c4(3, 4);
    cout << "\nc4 = " << c4 << endl;
    if (c1 == c4)
        cout << "c1 and c4 are equal" << endl;
    else
        cout << "c1 and c4 are not equal" << endl;

    if (c1 == c2)
        cout << "c1 and c2 are equal" << endl;
    else
        cout << "c1 and c2 are not equal" << endl;

    return 0;
}
