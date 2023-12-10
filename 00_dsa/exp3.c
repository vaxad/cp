#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
typedef struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
} Term;

// Function to create a new term
Term* createTerm(int coefficient, int exponent) {
    Term* newTerm = (Term*)malloc(sizeof(Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void addTerm(Term** polynomial, int coefficient, int exponent) {
    Term* newTerm = createTerm(coefficient, exponent);
    if (*polynomial == NULL) {
        *polynomial = newTerm;
    } else {
        Term* current = *polynomial;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to display the polynomial
void displayPolynomial(Term* polynomial) {
    if (polynomial == NULL) {
        printf("Polynomial is empty.\n");
    } else {
        Term* current = polynomial;
        while (current != NULL) {
            printf("%dx^%d ", current->coefficient, current->exponent);
            if (current->next != NULL) {
                printf("+ ");
            }
            current = current->next;
        }
        printf("\n");
    }
}

// Function to add two polynomials
Term* addPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                addTerm(&result, sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

// Function to subtract two polynomials
Term* subtractPolynomials(Term* poly1, Term* poly2) {
    Term* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, -poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int diff = poly1->coefficient - poly2->coefficient;
            if (diff != 0) {
                addTerm(&result, diff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        addTerm(&result, -poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

int main() {
    Term* poly1 = NULL;
    Term* poly2 = NULL;

    // Adding terms to the first polynomial
    addTerm(&poly1, 5, 4);
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 2, 1);

    // Adding terms to the second polynomial
    addTerm(&poly2, 4, 3);
    addTerm(&poly2, 2, 2);
    addTerm(&poly2, 1, 0);

    printf("First polynomial: ");
    displayPolynomial(poly1);

    printf("Second polynomial: ");
    displayPolynomial(poly2);

    Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of polynomials: ");
    displayPolynomial(sum);

    Term* difference = subtractPolynomials(poly1, poly2);
    printf("Difference of polynomials: ");
    displayPolynomial(difference);

    return 0;
}
