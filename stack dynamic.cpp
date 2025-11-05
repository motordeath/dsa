#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = *top;
    printf("Popped: %d\n", temp->data);
    *top = temp->next;
    free(temp);
}

void display(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    display(top);
    pop(&top);
    display(top);

    return 0;
}

