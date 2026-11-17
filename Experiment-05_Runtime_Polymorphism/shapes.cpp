#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual void display() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double r;
public:
    Circle(double x) { r = x; }
    double area() override { return 3.14 * r * r; }
    void display() override { cout << "Circle area: " << area() << endl; }
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double x, double y) { l = x; w = y; }
    double area() override { return l * w; }
    void display() override { cout << "Rectangle area: " << area() << endl; }
};

class Triangle : public Shape {
    double b, h;
public:
    Triangle(double x, double y) { b = x; h = y; }
    double area() override { return 0.5 * b * h; }
    void display() override { cout << "Triangle area: " << area() << endl; }
};

int main() {
    Shape *s[3];
    s[0] = new Circle(5);
    s[1] = new Rectangle(4, 6);
    s[2] = new Triangle(3, 8);

    for (int i = 0; i < 3; i++)
        s[i]->display();

    for (int i = 0; i < 3; i++)
        delete s[i];
    return 0;
}
