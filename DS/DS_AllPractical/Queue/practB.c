#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data ;
    struct Node* prev;
    struct Node* next;
};


struct Node* front = NULL;
struct Node* rear = NULL;

void enqueueAtfront(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Unable to assign memory.\n");
        return;
    }

    newNode->data = data;
    newNode->next = front;
    newNode->prev = NULL;
    if(front != NULL) {
        front->prev = newNode;
        front = newNode;
    }else{
        front = newNode;
        rear = newNode;
    }

}

void enqueueAtrear(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Unable to assign memory.\n");
        return;
    }
    newNode->data = data;
    newNode->prev = rear;
    newNode->next = NULL;
    if(rear != NULL) {
        rear->next = newNode;
        rear = newNode;
    }else {
        front = newNode;
        rear = newNode;
    }

}

void dequeueAtfront(){
    struct Node* temp = front;
    if(front == NULL && rear == NULL){
        printf("No element in queue, not possible to dequeue");
        return;
    }
    if(front == rear){
        temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
        return;
    }

    temp = front;
    front = front->next;
    free(temp);
}

void dequeueAtRear(){
    struct Node* temp = rear;
    if(front == NULL && rear == NULL){
        printf("No element in queue, not possible to dequeue");
        return;
    }
    if(front == rear){
        temp = front;
        front = NULL;
        rear = NULL;
        free(temp);
        return;
    }
    temp = rear;
    rear = rear->prev;
    free(temp);
}

void diplay(){
    struct Node* temp = front;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}



int main(){
    
    dequeueAtfront();

}