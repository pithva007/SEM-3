#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1, rear = -1;

void enqueueAtFront(int data) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1 == front)) {
        printf("Deque is Full\n");
        return;
    }

    if(front==-1 && rear==-1) {
        front =0;
        rear = 0;
    }
    else if(front==0) {
        front = MAX-1;  
    }
    else{
        front--;
    }

    deque[front] = data;
    printf("Enqueued at Front: %d\n", data);
}

void enqueueAtRear(int data) {

    if((front==0 && rear==MAX-1) || (rear+1 == front)) {
        printf("Deque is Full\n");
        return;
    }

    if(front==-1 && rear==-1) {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;  
    }
    else {
        rear++;
    }

    deque[rear] = data;
    printf("Enqueued at Rear: %d\n", data);
}

void dequeueAtFront() {
    if(front==-1 && rear==-1) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Dequeued from Front: %d\n", deque[front]);

    if(front==rear) {
        front = -1;
         rear = -1;
    }
    else if(front== MAX-1){
        front = 0; 
    }
    else{
        front++;
    }
}

void dequeueAtRear() {

    if(front==-1 && rear==-1) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Dequeued from Rear: %d\n", deque[rear]);

    if(front==rear) {
        front= -1;
        rear= -1;
    }
    else if(rear==0){
        rear = MAX-1;  
    }
    else {
        rear--;
    }
}

void display() {
    if(front==-1 && rear==-1) {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while(1){
        printf("%d ", deque[i]);
        if(i==rear) break;

        if(i==MAX-1)
            i = 0;
        else
            i++;
    }
    printf("\n");
}

int main() {
    int choice, data;
    while(1){
        printf("Options...\n");
        printf("1 for Enqueue at Front\n");
        printf("2 for Enqueue at Rear\n");
        printf("3 for Dequeue at Front\n");
        printf("4 for Dequeue at Rear\n");
        printf("5 for Display\n");
        printf("6 for Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                enqueueAtFront(data);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &data);
                enqueueAtRear(data);
                break;
            case 3:
                dequeueAtFront();
                break;
            case 4:
                dequeueAtRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}