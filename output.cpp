#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

struct Node* createNode(int x) {
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x; n->next = NULL;
    return n;
}

void insertBeg(int x) {
    struct Node *n = createNode(x);
    n->next = head;
    head = n;
}
void insertEnd(int x) {
    struct Node *n = createNode(x);
    if (head == NULL) { head = n; return; }
    struct Node *t = head;
    while (t->next) t = t->next;
    t->next = n;
}
void insertPos(int x, int pos) {
    if (pos == 1) { insertBeg(x); return; }
    struct Node *t = head;
    for (int i = 1; t && i < pos - 1; i++) t = t->next;
    if (!t) { printf("Invalid position\n"); return; }
    struct Node *n = createNode(x);
    n->next = t->next;
    t->next = n;
}
void deleteBeg() {
    if (!head) { printf("List empty\n"); return; }
    struct Node *t = head;
    head = head->next;
    free(t);
}
void deleteEnd() {
    if (!head) { printf("List empty\n"); return; }
    if (!head->next) { free(head); head = NULL; return; }
    struct Node *t = head;
    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
}
void deletePos(int pos) {
    if (pos == 1) { deleteBeg(); return; }
    struct Node *t = head;
    for (int i = 1; t && i < pos - 1; i++) t = t->next;
    if (!t || !t->next) { printf("Invalid position\n"); return; }
    struct Node *d = t->next;
    t->next = d->next;
    free(d);
}
void traverse(struct Node *p) {
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void traverseReverse(struct Node *p) {
    if (!p) return;
    traverseReverse(p->next);
    printf("%d ", p->data);
}
void search(int key) {
    struct Node *t = head;
    int pos = 1;
    while (t) {
        if (t->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        t = t->next; pos++;
    }
    printf("Not found\n");
}

int main() {
    int ch, x, pos, key;
    while (1) {
        printf("\n1.InsertBeg 2.InsertEnd 3.InsertPos 4.DelBeg 5.DelEnd 6.DelPos\n");
        printf("7.Traverse 8.TraverseReverse 9.Search 10.Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Data: "); scanf("%d",&x); insertBeg(x); break;
            case 2: printf("Data: "); scanf("%d",&x); insertEnd(x); break;
            case 3: printf("Data & position: "); scanf("%d%d",&x,&pos); insertPos(x,pos); break;
            case 4: deleteBeg(); break;
            case 5: deleteEnd(); break;
            case 6: printf("Position: "); scanf("%d",&pos); deletePos(pos); break;
            case 7: traverse(head); break;
            case 8: traverseReverse(head); printf("\n"); break;
            case 9: printf("Key: "); scanf("%d",&key); search(key); break;
            case 10: return 0;
            default: printf("Invalid\n");
        }
    }
}
