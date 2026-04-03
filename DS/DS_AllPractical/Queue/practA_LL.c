#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Unable to assign memory.\n");
    }

    newNode->data = data;
    newNode->next = NULL;
    if(rear == NULL){
        front = newNode;
        rear = newNode;
    }else{
        rear->next = newNode;
        rear = newNode;
    }
    
    printf("Enqueue operation done\n");
}

void dequeue(){
    struct Node* temp = front;
    if(front == NULL && rear == NULL){
        printf("Queue is empty, dequeue not possible\n");
    }else if(front == rear){
        printf("dequeued element: %d\n",front->data);
        front = NULL;
        rear = NULL;
    }else{
        printf("dequeued element: %d\n",front->data);
        front = front->next;
    }
    free(temp);
    temp = NULL;

}

void display(){
    if(front == NULL){
        printf("No element in queue.\n");
        return;
    }
    struct Node* temp = front;
    while(temp != NULL){
        printf("Element: %d\n", temp->data);
        temp = temp->next;
    }
    
}

int main(){
    int choice, data;
    while(1){
        printf("Options...\n");
        printf("1 for Enqueue\n");
        printf("2 for Dequeue\n");
        printf("3 for Display\n");
        printf("4 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting.....\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}