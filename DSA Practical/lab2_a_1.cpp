#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void create(int val) 
{
    Node* nnode = new Node{val, nullptr};
    if (!head) 
    {
        head = nnode;
    } 
    else 
    {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = nnode;
    }
    cout << "Node with value " << val << " created.\n";
}

int main() {
    int n, val;
    cout << "How many nodes do you want to add? ";
    cin >> n;
    cout << "Enter value for node : ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> val;
        create(val);
    }
    return 0;
}
