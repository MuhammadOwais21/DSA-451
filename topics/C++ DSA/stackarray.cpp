#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    if (top == MAX - 1)
    {
        cout << "Stack Overflow! Cannot push element." << endl;
        return;
    }
    int value;
    cout << "Enter value to push: ";
    cin >> value;
    top++;
    stack[top] = value;
    cout << value << " pushed into stack" << endl;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Underflow! Stack is empty" << endl;
        return;
    }
    cout << stack[top] << " popped from stack" << endl;
    top--;
}

void peek()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Top element is: " << stack[top] << endl;
    }
}

void display()
{
    if (top == -1)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
