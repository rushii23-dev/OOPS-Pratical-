#include <iostream>
#include <string>
using namespace std;

int num = 100;

int main() {
    int age = 19;
    float height = 5.8;
    double salary = 25000.75;
    char grade = 'A';
    bool pass = true;
    string name = "Rahul";
    const float PI = 3.14;
    constexpr int DAYS = 7;
    auto marks = 85;

    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Salary: " << salary << endl;
    cout << "Grade: " << grade << endl;
    cout << "Pass: " << pass << endl;
    cout << "PI: " << PI << ", Days: " << DAYS << ", Marks: " << marks << endl;
    cout << "Size of int: " << sizeof(int) << ", double: " << sizeof(double) << ", char: " << sizeof(char) << endl;

    int a, b;
    cout << "\nEnter two numbers: ";
    cin >> a >> b;

    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    if (b != 0) {
        cout << "a / b = " << a / b << endl;
        cout << "a % b = " << a % b << endl;
    }
    cout << "a > b : " << (a > b) << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a > 0 && b > 0 : " << (a > 0 && b > 0) << endl;
    cout << "a > 0 || b > 0 : " << (a > 0 || b > 0) << endl;
    a += 5;
    cout << "a += 5 : " << a << endl;
    a++;
    cout << "a++ : " << a << endl;

    int num = 50;
    cout << "\nLocal num: " << num << ", Global num: " << ::num << endl;

    int *p = new int(500);
    cout << "Value using new: " << *p << endl;
    delete p;
    p = nullptr;

    int arr[] = {10, 20, 30, 40, 50};
    cout << "Array: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
