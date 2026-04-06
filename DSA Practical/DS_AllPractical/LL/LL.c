#include <stdio.h>
#include <stdlib.h>
struct Poly {
    int coff;
    int pow;
    struct Poly* next;
};

struct Poly* makepoly(int a[], int n) {
    struct Poly* head = NULL;
    struct Poly* temp = NULL;

    for (int i = 0; i <= n; i++) {
        if (a[i] == 0) continue; 
        struct Poly* newNode = (struct Poly*)malloc(sizeof(struct Poly));
        newNode->coff = a[i];
        newNode->pow = n - i;
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Print polynomial in readable format
void printpoly(struct Poly* head) {
    while (head != NULL) {
        printf("%d(x^%d)", head->coff, head->pow);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

// Add two polynomials represented by linked lists
struct Poly* addpoly(struct Poly* p1, struct Poly* p2) {
    struct Poly* head = NULL;
    struct Poly* tail = NULL;

    while (p1 != NULL && p2 != NULL) {
        struct Poly* node = (struct Poly*)malloc(sizeof(struct Poly));
        node->next = NULL;

        if (p1->pow == p2->pow) {
            node->coff = p1->coff + p2->coff;
            node->pow = p1->pow;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->pow > p2->pow) {
            node->coff = p1->coff;
            node->pow = p1->pow;
            p1 = p1->next;
        } else {
            node->coff = p2->coff;
            node->pow = p2->pow;
            p2 = p2->next;
        }

        if (head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    // Append remaining terms from p1
    while (p1 != NULL) {
        struct Poly* node = (struct Poly*)malloc(sizeof(struct Poly));
        node->coff = p1->coff;
        node->pow = p1->pow;
        node->next = NULL;
        tail->next = node;
        tail = node;
        p1 = p1->next;
    }

    // Append remaining terms from p2
    while (p2 != NULL) {
        struct Poly* node = (struct Poly*)malloc(sizeof(struct Poly));
        node->coff = p2->coff;
        node->pow = p2->pow;
        node->next = NULL;
        tail->next = node;
        tail = node;
        p2 = p2->next;
    }

    return head;
}

int main() {
    int n1;
    printf("Enter the highest degree of Polynomial 1: ");
    scanf("%d", &n1);
    int a[n1 + 1];
    printf("Enter coefficients from highest degree to constant term:\n");
    for (int i = 0; i <= n1; i++) {
        scanf("%d", &a[i]);
    }
    struct Poly* head1 = makepoly(a, n1);

    int n2;
    printf("Enter the highest degree of Polynomial 2: ");
    scanf("%d", &n2);
    int b[n2 + 1];
    printf("Enter coefficients from highest degree to constant term:\n");
    for (int i = 0; i <= n2; i++) {
        scanf("%d", &b[i]);
    }
    struct Poly* head2 = makepoly(b, n2);

    printf("\nPolynomial 1: ");
    printpoly(head1);
    printf("Polynomial 2: ");
    printpoly(head2);

    struct Poly* sum = addpoly(head1, head2);
    printf("Sum: ");
    printpoly(sum);

    return 0;
}
