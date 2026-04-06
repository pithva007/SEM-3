#include <bits/stdc++.h>
using namespace std;

const int MAX = 3;
int arr[MAX];
int front = -1, rear = -1;

void enque(int x);
void deque1();
void display();

bool isempty() {
    return (front == -1 && rear == -1);
}

bool isfull() {
    return (rear == MAX - 1);
}

void enque(int x) {
    if (isfull()) {
        cout << "Queue is Full!" << endl;
        return;
    }
    if (isempty()) front = 0;  
    arr[++rear] = x;
}

void deque1() {
    if (isempty()) {
        cout << "Empty Queue" << endl;
        return;
    }
    int ans = arr[front];
    cout << "Element : " << ans << " dequeued" << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (isempty()) {
        cout << "Empty Queue" << endl;
        return;
    }
    cout << "Queue Elements: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    bool t = true;
    while (t) {
        cout << "----X----X----" << endl;
        cout << "1.enque \n2.deque \n3.display \n4.break\n";
        cout << "Enter Choice : ";
        int c;
        cin >> c;
        switch (c) {
        case 1: {
            cout << "Enter : ";
            int x; cin >> x;
            enque(x);
            break;
        }
        case 2:
            deque1();
            break;
        case 3:
            display();
            break;
        case 4:
            t = false;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
    return 0;
}
