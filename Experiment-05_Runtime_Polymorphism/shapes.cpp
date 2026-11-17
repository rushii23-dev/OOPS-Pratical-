/*
 * Experiment 5 : Runtime Polymorphism using Virtual Functions
 *                and an Abstract Base Class (Shape)
 *
 * Concepts used:
 *   - Abstract class (class with at least one pure virtual function)
 *   - Pure virtual function : virtual double area() = 0;
 *   - Virtual functions and function overriding
 *   - Base class pointer pointing to derived class objects
 *   - Virtual destructor
 *   - vtable : the table of virtual functions that C++ uses to decide,
 *              at runtime, which area() function to call
 */

#include <iostream>
#include <string>
using namespace std;

// ---------- Abstract base class ----------
class Shape
{
protected:
    string shapeName;

public:
    Shape(string name)
    {
        shapeName = name;
    }

    // Pure virtual function -> every child class MUST write its own area()
    virtual double area() = 0;

    // Normal virtual function (child class may override it)
    virtual void display()
    {
        cout << shapeName << " -> Area = " << area() << endl;
    }

    // Virtual destructor so that child destructor is also called
    virtual ~Shape()
    {
        cout << "Shape destructor (" << shapeName << ")" << endl;
    }
};

// ---------- Circle ----------
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape("Circle")
    {
        radius = r;
    }

    double area() override
    {
        return 3.14159 * radius * radius;
    }

    ~Circle()
    {
        cout << "Circle destructor" << endl;
    }
};

// ---------- Rectangle ----------
class Rectangle : public Shape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : Shape("Rectangle")
    {
        length = l;
        width = w;
    }

    double area() override
    {
        return length * width;
    }

    ~Rectangle()
    {
        cout << "Rectangle destructor" << endl;
    }
};

// ---------- Triangle ----------
class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h) : Shape("Triangle")
    {
        base = b;
        height = h;
    }

    double area() override
    {
        return 0.5 * base * height;
    }

    ~Triangle()
    {
        cout << "Triangle destructor" << endl;
    }
};

int main()
{
    // Shape s("Test");   // ERROR : cannot create object of abstract class

    // Array of base class pointers
    Shape *shapes[3];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Triangle(3, 8);

    cout << "===== Areas of Shapes (Runtime Polymorphism) =====" << endl;
    for (int i = 0; i < 3; i++)
    {
        // Same function call, but different area() runs for each shape
        shapes[i]->display();
    }

    double total = 0;
    for (int i = 0; i < 3; i++)
    {
        total = total + shapes[i]->area();
    }
    cout << "\nTotal area of all shapes = " << total << endl;

    cout << "\n===== Deleting Shapes =====" << endl;
    for (int i = 0; i < 3; i++)
    {
        delete shapes[i];   // virtual destructor makes this safe
    }

    return 0;
}
