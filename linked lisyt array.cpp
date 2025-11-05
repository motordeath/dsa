#include <stdio.h>

struct Node {
    int data;
    int next;
};

int main() {
    struct Node list[5];
    int n = 3;

    // Initialize linked list
    list[0].data = 10; list[0].next = 1;
    list[1].data = 20; list[1].next = 2;
    list[2].data = 30; list[2].next = -1;

    int head = 0;
    printf("Static Linked List:\n");
    for (int i = head; i != -1; i = list[i].next)
        printf("%d -> ", list[i].data);
    printf("NULL\n");

    return 0;
}

