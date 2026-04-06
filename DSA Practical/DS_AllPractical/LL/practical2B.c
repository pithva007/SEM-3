
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int coeff;
    int pow;
    struct Node* next;
};

struct Node* createNode(int c, int p);

struct Node* addPolynomial(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;   
    if (head1->pow > head2->pow){
        struct Node* nextPtr =addPolynomial(head1->next, head2);
        head1->next = nextPtr;
        return head1;
    }
   
    else if (head1->pow < head2->pow) {
        struct Node* nextPtr = addPolynomial(head1, head2->next);
        head2->next = nextPtr;
        return head2;
    }

   
    struct Node* nextPtr = addPolynomial(head1->next, head2->next);
    head1->coeff += head2->coeff;
    head1->next = nextPtr;
    return head1;
}


void printList(struct Node* head) {
    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d,%d ", curr->coeff, curr->pow);
        curr = curr->next;

    }

    printf("\n");
}

struct Node* createNode(int c, int p) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->pow = p;
    newNode->next = NULL;
    return newNode;
}


int main() {
    
    struct Node* head1 = createNode(5, 2);
    head1->next = createNode(4, 1);
    head1->next->next = createNode(2, 0);

    struct Node* head2 = createNode(-5, 1);
    head2->next = createNode(-5, 0);

    struct Node* head = addPolynomial(head1, head2);

    printList(head);

    return 0;
}