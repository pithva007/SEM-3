#include <stdio.h>
#define MAX 5  

int stack[MAX];
int top = -1;


void push(int x){
    if(top == MAX - 1){
        printf("Stack is full(overflow)\n");
    }else{
        stack[++top] = x;
        printf("%d pushed to stack\n", x);
    }
}


void pop(){
    if(top == -1){
        printf("Stack is empty(underflow)\n");
    } else {
        printf("%d popped from stack\n", stack[top--]);
    }
}


int peek(){
    if(top == -1){
        printf("Stack is Empty\n");
        return -1;
    } else {
        return stack[top];
    }
}


int isEmpty(){
    return top == -1;
}


void display(){
    if(top==-1){
        printf("Stack is Empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, val;

    while(1){
        printf("Options...\n");
        printf("1 for Push\n");
        printf("2 for Pop\n");
        printf("3 forPeek\n");
        printf("4 for Display\n");
        printf("5 for Check Empty\n");
        printf("6 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                val = peek();
                if(val != -1) 
                    printf("Top element is %d\n", val);
                break;

            case 4:
                display();
                break;

            case 5:
                if(isEmpty())
                    printf("Stack is Empty\n");
                else
                    printf("Stack is NOT Empty\n");
                break;

            case 6:
                printf("Exiting.....\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
