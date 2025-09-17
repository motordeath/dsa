#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    int data;
    int next;
};

Node nodes[SIZE];
int head = -1;
int avail = 0;

void initNodes() {
    for (int i = 0; i < SIZE - 1; i++) {
        nodes[i].next = i + 1;
    }
    nodes[SIZE - 1].next = -1;
}

int getNode() {
    if (avail == -1) {
        cout << "No free space available!\n";
        return -1;
    }
    int newIndex = avail;
    avail = nodes[avail].next;
    return newIndex;
}

void freeNode(int index) {
    nodes[index].next = avail;
    avail = index;
}

void insertFront(int val) {
    int newIndex = getNode();
    if (newIndex == -1) return;
    nodes[newIndex].data = val;
    nodes[newIndex].next = head;
    head = newIndex;
}

void insertEnd(int val) {
    int newIndex = getNode();
    if (newIndex == -1) return;
    nodes[newIndex].data = val;
    nodes[newIndex].next = -1;

    if (head == -1) {
        head = newIndex;
        return;
    }

    int temp = head;
    while (nodes[temp].next != -1) {
        temp = nodes[temp].next;
    }
    nodes[temp].next = newIndex;
}

void insertAfter(int key, int val) {
    int temp = head;
    while (temp != -1 && nodes[temp].data != key) {
        temp = nodes[temp].next;
    }
    if (temp == -1) {
        cout << "Key not found!\n";
        return;
    }
    int newIndex = getNode();
    if (newIndex == -1) return;
    nodes[newIndex].data = val;
    nodes[newIndex].next = nodes[temp].next;
    nodes[temp].next = newIndex;
}

void deleteFront() {
    if (head == -1) return;
    int temp = head;
    head = nodes[head].next;
    freeNode(temp);
}

void deleteEnd() {
    if (head == -1) return;
    if (nodes[head].next == -1) {
        freeNode(head);
        head = -1;
        return;
    }
    int temp = head;
    while (nodes[nodes[temp].next].next != -1) {
        temp = nodes[temp].next;
    }
    int last = nodes[temp].next;
    nodes[temp].next = -1;
    freeNode(last);
}

void deleteAfter(int key) {
    int temp = head;
    while (temp != -1 && nodes[temp].data != key) {
        temp = nodes[temp].next;
    }
    if (temp == -1 || nodes[temp].next == -1) return;
    int target = nodes[temp].next;
    nodes[temp].next = nodes[target].next;
    freeNode(target);
}

void printList() {
    int temp = head;
    while (temp != -1) {
        cout << nodes[temp].data << " -> ";
        temp = nodes[temp].next;
    }
    cout << "NULL\n";
}

int main() {
    initNodes();

    insertFront(10);
    insertFront(20);
    insertEnd(30);
    insertAfter(10, 40);
    insertEnd(50);
    printList();

    deleteFront();
    printList();

    deleteEnd();
    printList();

    deleteAfter(10);
    printList();
}

