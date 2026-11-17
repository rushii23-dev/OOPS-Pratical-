#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

int add(int a, int b, int c) {
    return a + b + c;
}

class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    bool operator==(Complex c) {
        return real == c.real && imag == c.imag;
    }

    friend ostream &operator<<(ostream &out, Complex c);
};

ostream &operator<<(ostream &out, Complex c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

int main() {
    cout << "Function Overloading" << endl;
    cout << "add(10, 20) = " << add(10, 20) << endl;
    cout << "add(2.5, 3.5) = " << add(2.5, 3.5) << endl;
    cout << "add(1, 2, 3) = " << add(1, 2, 3) << endl;

    cout << "\nOperator Overloading" << endl;
    Complex c1(3, 4), c2(1, 2);
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c1 + c2 = " << c1 + c2 << endl;
    cout << "c1 - c2 = " << c1 - c2 << endl;
    if (c1 == c2)
        cout << "c1 and c2 are equal" << endl;
    else
        cout << "c1 and c2 are not equal" << endl;
    return 0;
}
