#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
private:
    T arr[5];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(T x) {
        if (top == 4) {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    T pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return T();
        }
        T x = arr[top];
        top--;
        return x;
    }

    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << "Int stack: ";
    s1.display();
    cout << "Popped: " << s1.pop() << endl;

    Stack<float> s2;
    s2.push(1.5);
    s2.push(2.5);
    cout << "\nFloat stack: ";
    s2.display();
    cout << "Popped: " << s2.pop() << endl;

    Stack<string> s3;
    s3.push("C++");
    s3.push("Java");
    s3.push("Python");
    cout << "\nString stack: ";
    s3.display();
    cout << "Popped: " << s3.pop() << endl;

    cout << "\nOverflow test" << endl;
    Stack<int> s4;
    for (int i = 1; i <= 6; i++)
        s4.push(i);
    return 0;
}
