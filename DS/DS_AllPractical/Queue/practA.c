#include<stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
void enqueue(int data){
    if(rear == MAX-1){
        printf("Queue is Full.\n");
        return;
    }else{
        if(front == -1 && rear == -1) front = 0;
        rear++;
        queue[rear] = data;
        printf("enqueue operation done.\n");
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty so you can't delete anything.\n");
    }else if(front == rear){
        printf("dequeued element %d\n",queue[front]);
        front = -1;
        rear = -1;
    }else{
        printf("dequeued element %d\n",queue[front]);
        front++;
    }
}


void display(){
    
    for(int i = front; i<=rear; i++){
        if(i<0){
            printf("there are no elements\n");
            return;
        }else{
            printf("Element: %d\n", queue[i]);
        }
    }
}


int main() {
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
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}