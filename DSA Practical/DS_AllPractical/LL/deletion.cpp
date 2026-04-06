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
Node* deletehead(Node* head){
    if(head==NULL) return head;
    //Node* temp = head;
    head = head->next;
    //free(temp); //delete temp
    return head;
}

Node* deletetail(Node* head){
    Node* temp = head;
    if(head==NULL || head->next == NULL) return NULL;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

// Node* deleteKthNode(int k, Node* head){
//     if(k==1) return 
// }
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " " << endl;
        temp = temp->next;
    }
}

int main(){
    vector<int> v = { 1,2,3,4};
    //delete head of LinkedList;
    Node* head = converter(v);
    print(head);
    Node* newHead = deletehead(head);
    print(newHead);
    Node* delTail = deletetail(newHead);
    print(delTail);

    


}