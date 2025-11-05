#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coeff, pow;
    struct Poly* next;
};

void display(struct Poly* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        if (poly->next != NULL) printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    struct Poly *p1, *p2, *p3;
    p1 = (struct Poly*)malloc(sizeof(struct Poly));
    p2 = (struct Poly*)malloc(sizeof(struct Poly));
    p3 = (struct Poly*)malloc(sizeof(struct Poly));

    p1->coeff = 3; p1->pow = 2; p1->next = p2;
    p2->coeff = 2; p2->pow = 1; p2->next = p3;
    p3->coeff = 1; p3->pow = 0; p3->next = NULL;

    printf("Polynomial: ");
    display(p1);

    return 0;
}

