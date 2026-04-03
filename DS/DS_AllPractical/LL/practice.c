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
void addAtgiven(int data, int pos);
void deleteAtbeg();
void deleteAtEnd();
void deleteAtgiven(int pos);

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
            
            case 5:
                int pos;
                scanf("%d", &data);
                scanf("%d", &pos);
                addAtgiven(data, pos);
                break;
            case 6:
                deleteAtbeg();
                break;

            case 7:
                deleteAtEnd();
                break;

            case 8:
                scanf("%d", &pos);
                deleteAtgiven(pos);
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
        printf("5. add at Any pos\n");
        printf("6. delete at begining\n");
        printf("7. delete at end\n");
        printf("8. delete at any pos\n");

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
    if(temp==NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void addAtgiven(int data, int pos){
    int cnt = 1;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    struct Node* temp = head;

    while(temp!=NULL){
        if(cnt == pos-1){
            break;
        }
        temp = temp->next;
        cnt++;
    }
    struct Node* nxt = temp->next;
    temp->next = newNode;
    newNode->next = nxt;
    
}

void deleteAtbeg(){
    struct Node* temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}

void deleteAtEnd(){
    struct Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    struct Node* tobedelete = temp->next;
    temp->next = NULL;
    free(tobedelete);
    tobedelete = NULL;


}

void deleteAtgiven(int pos){
    struct Node* temp = head;
    int cnt = 1;
    while(temp != NULL){
        if(cnt == pos-1){
            break;
        }
        temp = temp->next;
        cnt++;
    }
    struct Node* tobedelete = temp->next;
    temp->next = temp->next->next;
    free(tobedelete);
    tobedelete = NULL;
}