#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name, number;
    Node *left, *right;
    Node(string n, string num) 
    {
        name=n; 
        number=num;
        left=right=NULL;
    }
};

Node* insert(Node* root, string name, string number) 
{
    if(root == NULL) return new Node(name,number);
    if(name < root->name) root->left = insert(root->left,name,number);
    else if(name > root->name) root->right = insert(root->right,name,number);
    else cout<<"Entry for "<<name<<" already exists.\n";
    return root;
}

Node* search(Node* root, string name) {
    if(root == NULL || root->name==name) return root;
    if(name < root->name) return search(root->left,name);
    return search(root->right,name);
}

void printasc(Node* root) {
    if(root == NULL ) return;
    printasc(root->left);
    cout<<root->name<<" : "<<root->number<<"\n";
    printasc(root->right);
}

void printdes(Node* root) {
    if(root == NULL) return;
    printdes(root->right);
    cout<<root->name<<" : "<<root->number<<"\n";
    printdes(root->left);
}

Node* findMin(Node* root) {
    while(root->left != NULL) root = root->left;
    return root;
}
Node* remove(Node* root,string name) {
    if(root == NULL) {
        cout<<"Entry for "<<name<<" does not exist.\n";
        return root;
    }
    if(name < root->name) root->left = remove(root->left,name);
    else if(name > root->name) root->right = remove(root->right,name);
    else {
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->name = temp->name;
        root->number = temp->number;
        root->right = remove(root->right,temp->name);
    }
}

int main() {
    Node* root=NULL;
    int ch; bool f=true;
    while(f) {
        cout<<"\n1.Add \n2.Remove \n3.Search \n4.Asc \n5.Desc \n6.Exit\nEnter your choice: ";
        cin>>ch;
        string n,num;
        switch(ch) {
            case 1: 
                cout<<"Name: "; 
                cin>>n; 
                cout<<"Number: "; 
                cin>>num; 
                root=insert(root,n,num); 
                break;
            case 2: 
                cout<<"Name: "; 
                cin>>n; 
                root=remove(root,n); 
                break;
            case 3: 
                cout<<"Name: "; 
                cin>>n; 
                {
                    Node* t=search(root,n);
                    if(!t) cout<<"Not found\n";
                    else cout<<t->name<<" : "<<t->number<<"\n";
                } 
                break;
            case 4: 
                printasc(root); 
                break;
            case 5: 
                printdes(root); 
                break;
            case 6: f=false; break;
        }
    }
    return 0;
}