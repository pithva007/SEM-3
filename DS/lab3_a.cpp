#include <bits/stdc++.h>
using namespace std;

#define MAX 100   
int arr[MAX];    
int top = -1;    


void push(int value) 
{
    if (top == MAX - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        top++;
        arr[top] = value;
        cout << value << " pushed." << endl;
    }
}


void pop() {
    if (top == -1) {
        cout << "Stack Underflow!" << endl;
    } else {
        cout << arr[top] << " popped." << endl;
        top--;
    }
}


void peek() {
    if (top == -1) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Top element: " << arr[top] << endl;
    }
}


void display() {
    if (top == -1) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek (Top)\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1: 
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;

            case 2: 
                pop();
                break;

            case 3: 
                peek();
                break;

            case 4: 
                display();
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
