#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

void insert(struct Node** head, int coeff, int power) {
    if (coeff == 0) return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    if (*head == NULL || (*head)->power < power) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->power > power)
            temp = temp->next;

        if (temp->power == power) {
            temp->coeff += coeff;
            free(newNode);
        } else if (temp->next != NULL && temp->next->power == power) {
            temp->next->coeff += coeff;
            free(newNode);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->power);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

struct Node* create_polynomial() {
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    struct Node* poly = NULL;
    for (int i = degree; i >= 0; i--) {
        int coeff;
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &coeff);
        insert(&poly, coeff, i);
    }

    return poly;
}

struct Node* add_polynomials(struct Node* p1, struct Node* p2) {
    struct Node* sum = NULL;

    while (p1 && p2) {
        if (p1->power > p2->power) {
            insert(&sum, p1->coeff, p1->power);
            p1 = p1->next;
        } else if (p1->power < p2->power) {
            insert(&sum, p2->coeff, p2->power);
            p2 = p2->next;
        } else {
            insert(&sum, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1) {
        insert(&sum, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while (p2) {
        insert(&sum, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return sum;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    int choice;
    do {
        
        printf("1. Create Polynomial 1\n");
        printf("2. Create Polynomial 2\n");
        printf("3. Display Both Polynomials\n");
        printf("4. Add Polynomials and Display Result\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                poly1 = create_polynomial();
                break;
            case 2:
                poly2 = create_polynomial();
                break;
            case 3:
                printf("Polynomial 1: ");
                display(poly1);
                printf("Polynomial 2: ");
                display(poly2);
                break;
            case 4:
                result = add_polynomials(poly1, poly2);
                printf("Sum of Polynomials: ");
                display(result);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
