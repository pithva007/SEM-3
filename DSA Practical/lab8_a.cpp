#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  int data;
  struct Node* next;
} Node;

Node* hashtable[10];

int hashfnc(int key){
  return key % 10;
}

Node* createNode(int key){
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = key;
  newNode->next = NULL;
  return newNode;
}

void insert(int d){
  int idx = hashfnc(d);
  Node* newNode = createNode(d);

  if(hashtable[idx] == NULL){
    hashtable[idx] = newNode;
  }
  else{
    Node* temp = hashtable[idx];

    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

void display(){
  for(int i=0; i<10; i++){
    printf("Index %d : ", i);
    Node* temp = hashtable[i];
    if(temp == NULL){
      printf("NULL");
    }
    else{
      while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
      }
      printf("NULL");
    }
    printf("\n");
  }
}

int main() {
    for (int i = 0; i < 10; i++) {
        hashtable[i] = NULL;
    }

    int sz;
    printf("Enter number of elements to insert: ");
    scanf("%d", &sz);

    int elements[sz];

    printf("Enter %d elements:\n", sz);
    for (int i = 0; i < sz; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &elements[i]);
        insert(elements[i]);
    }

    printf("\nHash Table\n");
    display();

    return 0;
}
