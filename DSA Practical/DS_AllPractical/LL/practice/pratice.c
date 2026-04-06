#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

void loadMenu();
void createLL();
void printLL();
void addAtbeg(int);
void addAtLast(int);

int main(){
    while(1){
         loadMenu();    
         int n;
         scanf("%d", &n);
         switch(n){
             case 1:
                 createLL();
                 break;
             case 2:
                 printLL();
                 break;

             case 3:
                int data;
                scanf("%d", &data);
                addAtbeg(data);
                break;

            case 4:
                scanf("%d", &data);
                addAtLast(data);
                break;
            default:
                exit(1);
            
         }

    }
   
}


void loadMenu(){
    
        printf("1. Create LL \n");
        printf("2. print LL \n");
        printf("3. add at begining \n");
        printf("4. add at last\n");

}
    

void createLL(){
    head = (struct Node*)malloc(sizeof(struct Node));
    if(head==NULL){
        printf("Unable to allocate memory");
    }
    struct Node* temp = head;
    int n;
    printf("Enter No. of Node");
    scanf("%d", &n);
    int data;
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    for(int i=1; i<n; i++){
        int data1;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->next = NULL;
        if(newNode == NULL){
            printf("Unable to allocate memory");
        }
        scanf("%d", &data1);
        newNode->data = data1;
        temp->next = newNode;
        temp = temp->next;
    }

}


void printLL(){
    struct Node* temp= head;
    while(temp != NULL){
        printf("%d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

void addAtbeg(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}


void addAtLast(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}