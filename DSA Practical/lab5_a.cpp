#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void insert(Node* root, int val) {
    char choice;
    cout << "Insert " << val << " to the left or right of " << root->data << "? (L/R): ";
    cin >> choice;

    if (choice == 'L' || choice == 'l') {
        if (root->left == nullptr) {
            root->left = new Node(val);
        } else {
            insert(root->left, val);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new Node(val);
        } else {
            insert(root->right, val);
        }
    }
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int n, val;

    if (n <= 0) {
        cout << "Tree must have at least one node!" << endl;
        return 0;
    }
    cout << "Enter value for root node: ";
    cin >> val;
    root = new Node(val);

    while (true){
        cout << "Enter value for new node: ";
        cin >> val;
        if(val == -1) break;
        insert(root, val);
        
    } 

    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;
    return 0;
}