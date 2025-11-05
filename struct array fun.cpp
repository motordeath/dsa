#include <stdio.h>

struct Array {
    int data[50];
    int size;
};

void insert(struct Array *arr, int pos, int val) {
    for (int i = arr->size; i >= pos; i--)
        arr->data[i] = arr->data[i - 1];
    arr->data[pos - 1] = val;
    arr->size++;
}

void delet(struct Array *arr, int pos) {
    for (int i = pos - 1; i < arr->size - 1; i++)
        arr->data[i] = arr->data[i + 1];
    arr->size--;
}

void display(struct Array arr) {
    for (int i = 0; i < arr.size; i++)
        printf("%d ", arr.data[i]);
    printf("\n");
}

int main() {
    struct Array arr;
    arr.size = 0;
    int choice, pos, val;

    do {
        printf("\n1. Insert 2. Delete 3. Display 4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter position and value: ");
                scanf("%d %d", &pos, &val);
                insert(&arr, pos, val);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", pos);
                delet(&arr, pos);
                break;
            case 3:
                display(arr);
                break;
        }
    } while (choice != 4);

    return 0;
}

