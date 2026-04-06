#include <iostream>
using namespace std;

// Define structure for polynomial term
class Node {
public:
    int coeff;
    int exp;
    Node* next;

    Node(int c, int e) {
        coeff = c;
        exp = e;
        next = nullptr;
    }
};

// Function to insert a term at the end of linked list
Node* insertTerm(Node* head, int coeff, int exp) {
    Node* newNode = new Node(coeff, exp);
    if (head == nullptr) return newNode;

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Function to display a polynomial
void displayPoly(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->exp;
        poly = poly->next;
        if (poly) cout << " + ";
    }
    cout << endl;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            result = insertTerm(result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp) {
            result = insertTerm(result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else { // Same exponent
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0)  // Avoid inserting zero coefficient
                result = insertTerm(result, sum, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms
    while (poly1) {
        result = insertTerm(result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2) {
        result = insertTerm(result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Main function
int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    // Polynomial 1: 3x^3 + 4x^2 + 2
    poly1 = insertTerm(poly1, 3, 3);
    poly1 = insertTerm(poly1, 4, 2);
    poly1 = insertTerm(poly1, 2, 0);

    // Polynomial 2: 5x^2 + 6x + 1
    poly2 = insertTerm(poly2, 5, 2);
    poly2 = insertTerm(poly2, 6, 1);
    poly2 = insertTerm(poly2, 1, 0);

    cout << "Polynomial 1: ";
    displayPoly(poly1);

    cout << "Polynomial 2: ";
    displayPoly(poly2);

    Node* result = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    displayPoly(result);

    return 0;
}
