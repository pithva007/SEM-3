#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* converter(vector<int> &v){
    Node* head = new Node(v[0]);
    Node* mover = head;
    for(int i=1; i<v.size(); i++){
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int LengthOfLL(Node* head){
    int cnt = 0;
    Node* temp = head; 
    while(temp !=nullptr){  
       // cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;

}

int main(){
    vector<int> a = {12,3,4,5,6};
    Node* y = new Node(a[0], nullptr);
    //cout << y->next << endl;
    Node* head = converter(a);
    //cout << head->data;

    //traverse the linkedList:
    // Node* temp = head; 
    // while(temp !=nullptr){  //not temp->next
    //     cout << temp->data << " ";
    //     temp = temp->next;
    // }

    //length of LinkedList
    cout << LengthOfLL(head);
}