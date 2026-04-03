#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node{
    int k;
    struct Node* next;
};

struct Node* ht[SIZE];

int hash(int k){
    return (2*k+3)%SIZE;
}

struct Node* newNode(int k){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->k = k;
    n->next = NULL;
    return n;
}

void insert(int k){
    int i = hash(k);
    struct Node* n = newNode(k);
    n->next = ht[i];
    ht[i] = n;
}

void show(){
    for(int i = 0; i<SIZE; i++){
        printf("%d: ", i);
        struct Node* t = ht[i];
        while(t){
            printf("%d -> ",t->k);
            t = t->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n;
    printf("Enter NUmber of Keys/ data : ");
    scanf("%d", &n);
    int a[n];
    for(int i =0 ;i<n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i<SIZE; i++)
        ht[i] = NULL;

    for (int i = 0; i<n; i++)
        insert(a[i]);

    show();
    return 0;
}
