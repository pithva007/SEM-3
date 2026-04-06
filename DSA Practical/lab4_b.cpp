#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }


    void insertFront(int x) {
        Node* newNode = new Node(x);
        if (!front) { 
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
        cout << x << " inserted at front" << endl;
    }

     
    void insertRear(int x) {
        Node* newNode = new Node(x);
        if (!rear) { 
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
        cout << x << " inserted at rear" << endl;
    }

    
    void deleteFront() {
        if (!front) {
            cout << "Deque is empty" << endl;
            return;
        }
        int val = front->data;
        Node* temp = front;
        if (front == rear) { 
            front = rear = NULL;
        } else {
            front = front->next;
            front->prev = NULL;
        }
        delete temp;
        cout << val << " deleted from front" << endl;
    }

    
    void deleteRear() {
        if (!rear) {
            cout << "Deque is empty" << endl;
            return;
        }
        int val = rear->data;
        Node* temp = rear;
        if (front == rear) { 
            front = rear = NULL;
        } else {
            rear = rear->prev;
            rear->next = NULL;
        }
        delete temp;
        cout << val << " deleted from rear" << endl;
    }

    
    void display() {
        if (!front) {
            cout << "Deque is empty" << endl;
            return;
        }
        cout << "Deque elements: ";
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    bool t = true;

    while (t) {
        cout << "\n----X----X----" << endl;
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n";
        cout << "Enter choice: ";
        int c, x;
        cin >> c;

        switch (c) {
        case 1:
            cout << "Enter value: ";
            cin >> x;
            dq.insertFront(x);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> x;
            dq.insertRear(x);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            t = false;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
