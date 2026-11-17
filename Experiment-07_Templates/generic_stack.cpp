/*
 * Experiment 7 : Generic Stack using Templates
 *                Tested with int, float and std::string
 *
 * Concepts used:
 *   - Class template  : template <typename T> class Stack
 *   - Function template : template <typename T> void showTop(...)
 *   - Same code works for many data types (generic programming)
 *   - Stack : LIFO (Last In First Out)
 */

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 5;

template <typename T>
class Stack
{
private:
    T items[MAX_SIZE];
    int top;

public:
    Stack()
    {
        top = -1;     // -1 means the stack is empty
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }

    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        top++;
        items[top] = value;
        cout << "Pushed : " << value << endl;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Nothing to pop" << endl;
            return T();     // return a default value
        }
        T value = items[top];
        top--;
        return value;
    }

    T peek()
    {
        if (isEmpty())
        {
            return T();
        }
        return items[top];
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom) : ";
        for (int i = top; i >= 0; i--)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

// Function template
template <typename T>
void showTop(Stack<T> &s)
{
    cout << "Top element : " << s.peek() << ", Size : " << s.size() << endl;
}

int main()
{
    cout << "===== Stack of int =====" << endl;
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);
    intStack.display();
    showTop(intStack);
    cout << "Popped : " << intStack.pop() << endl;
    intStack.display();

    cout << "\n===== Stack of float =====" << endl;
    Stack<float> floatStack;
    floatStack.push(1.5f);
    floatStack.push(2.75f);
    floatStack.push(3.25f);
    floatStack.display();
    showTop(floatStack);
    cout << "Popped : " << floatStack.pop() << endl;
    floatStack.display();

    cout << "\n===== Stack of string =====" << endl;
    Stack<string> stringStack;
    stringStack.push("C++");
    stringStack.push("Java");
    stringStack.push("Python");
    stringStack.display();
    showTop(stringStack);
    cout << "Popped : " << stringStack.pop() << endl;
    stringStack.display();

    cout << "\n===== Overflow and Underflow Test =====" << endl;
    Stack<int> testStack;
    for (int i = 1; i <= 6; i++)    // 6th push will overflow
    {
        testStack.push(i * 100);
    }
    while (!testStack.isEmpty())
    {
        cout << "Popped : " << testStack.pop() << endl;
    }
    testStack.pop();                // underflow

    return 0;
}
