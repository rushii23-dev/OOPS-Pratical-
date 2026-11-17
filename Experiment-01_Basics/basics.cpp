/*
 * Experiment 1 : Data Types, Constants, Variables, Operators and I/O
 *
 * Concepts used:
 *   - Basic data types (int, float, double, char, bool, string)
 *   - Constants (const and constexpr)
 *   - Variables and the auto keyword
 *   - Operators (arithmetic, relational, logical, assignment, increment)
 *   - Scope resolution operator (::)
 *   - Memory management operators (new and delete), nullptr
 *   - Range-based for loop
 *   - Console input / output (cin and cout)
 */

#include <iostream>
#include <string>
using namespace std;

// Global variable (used to show the scope resolution operator)
int number = 100;

// constexpr : value is fixed at compile time
constexpr double PI = 3.14159;

int main()
{
    cout << "===== 1. Data Types and Variables =====" << endl;

    int age = 19;
    float height = 5.8f;
    double salary = 25000.75;
    char grade = 'A';
    bool isStudent = true;
    string name = "Rahul";

    cout << "Name       : " << name << endl;
    cout << "Age        : " << age << endl;
    cout << "Height     : " << height << endl;
    cout << "Salary     : " << salary << endl;
    cout << "Grade      : " << grade << endl;
    cout << "Is Student : " << isStudent << endl;

    cout << "\nSize of int    : " << sizeof(int) << " bytes" << endl;
    cout << "Size of float  : " << sizeof(float) << " bytes" << endl;
    cout << "Size of double : " << sizeof(double) << " bytes" << endl;
    cout << "Size of char   : " << sizeof(char) << " bytes" << endl;
    cout << "Size of bool   : " << sizeof(bool) << " bytes" << endl;

    cout << "\n===== 2. Constants =====" << endl;

    const int DAYS_IN_WEEK = 7;          // const : value cannot be changed
    cout << "Days in a week : " << DAYS_IN_WEEK << endl;
    cout << "Value of PI    : " << PI << endl;
    // DAYS_IN_WEEK = 8;   // ERROR : cannot change a constant

    cout << "\n===== 3. auto keyword =====" << endl;

    auto marks = 85;          // compiler decides the type -> int
    auto percent = 85.5;      // -> double
    auto letter = 'B';        // -> char
    cout << "marks = " << marks << ", percent = " << percent
         << ", letter = " << letter << endl;

    cout << "\n===== 4. Input from user =====" << endl;

    int a, b;
    cout << "Enter first number  : ";
    cin >> a;
    cout << "Enter second number : ";
    cin >> b;

    cout << "\n===== 5. Arithmetic Operators =====" << endl;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    if (b != 0)
    {
        cout << a << " / " << b << " = " << a / b << endl;
        cout << a << " % " << b << " = " << a % b << endl;
    }
    else
    {
        cout << "Division by zero is not allowed" << endl;
    }

    cout << "\n===== 6. Relational Operators =====" << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;
    cout << "a > b  : " << (a > b) << endl;
    cout << "a < b  : " << (a < b) << endl;
    cout << "a >= b : " << (a >= b) << endl;
    cout << "a <= b : " << (a <= b) << endl;

    cout << "\n===== 7. Logical Operators =====" << endl;
    cout << "(a > 0 && b > 0) : " << (a > 0 && b > 0) << endl;
    cout << "(a > 0 || b > 0) : " << (a > 0 || b > 0) << endl;
    cout << "!(a > 0)         : " << !(a > 0) << endl;

    cout << "\n===== 8. Assignment and Increment Operators =====" << endl;
    int x = 10;
    cout << "x = " << x << endl;
    x += 5;
    cout << "x += 5  -> " << x << endl;
    x -= 3;
    cout << "x -= 3  -> " << x << endl;
    x *= 2;
    cout << "x *= 2  -> " << x << endl;
    x /= 4;
    cout << "x /= 4  -> " << x << endl;
    x++;
    cout << "x++     -> " << x << endl;
    x--;
    cout << "x--     -> " << x << endl;

    cout << "\n===== 9. Scope Resolution Operator (::) =====" << endl;
    int number = 50;   // local variable with same name as global
    cout << "Local number  : " << number << endl;
    cout << "Global number : " << ::number << endl;

    cout << "\n===== 10. new and delete (Memory Management) =====" << endl;
    int *ptr = nullptr;       // nullptr : pointer pointing to nothing
    ptr = new int;            // allocate memory for one int
    *ptr = 500;
    cout << "Value stored in dynamic memory : " << *ptr << endl;
    delete ptr;               // free the memory
    ptr = nullptr;

    int *arr = new int[5];    // allocate memory for an array
    for (int i = 0; i < 5; i++)
    {
        arr[i] = (i + 1) * 10;
    }
    cout << "Dynamic array : ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;             // free the array memory

    cout << "\n===== 11. Range-based for loop =====" << endl;
    int scores[] = {70, 80, 90, 60, 75};
    cout << "Scores : ";
    for (int s : scores)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
