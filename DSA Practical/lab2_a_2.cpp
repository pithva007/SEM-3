#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node* link;
};

node* root = nullptr;

void append(int x) 
{
    node* n = new node{x, nullptr};
    if (root == nullptr)
        root = n;
    else {
        node* current = root;
        while (current->link != nullptr)
            current = current->link;
        current->link = n;
    }
}

void remove(int target) 
{
    if (root == nullptr) {
        cout << "No nodes in the list.\n";
        return;
    }

    node* curr = root;
    node* prev = nullptr;

    if (root->data == target) {
        root = root->link;
        delete curr;
        cout << "Deleted value: " << target << endl;
        return;
    }

    while (curr != nullptr && curr->data != target) {
        prev = curr;
        curr = curr->link;
    }

    if (curr == nullptr) {
        cout << "Element " << target << " not present.\n";
    } else {
        prev->link = curr->link;
        delete curr;
        cout << "Deleted value: " << target << endl;
    }
}

int main() {
    append(100);
    append(200);
    append(300);

    int delVal;
    cout << "Enter value to remove: ";
    cin >> delVal;

    remove(delVal);

    return 0;
}
