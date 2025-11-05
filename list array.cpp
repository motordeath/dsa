#include <iostream>
using namespace std;

const int SIZE = 10; 
int dataArr[SIZE], nextArr[SIZE];
int head = -1, freeIndex = 0;


void init() {
    for (int i = 0; i < SIZE - 1; i++) nextArr[i] = i + 1;
    nextArr[SIZE - 1] = -1;
}


int getNode() {
    if (freeIndex == -1) return -1;
    int idx = freeIndex;
    freeIndex = nextArr[freeIndex];
    return idx;
}


void insertHead(int val) {
    int idx = getNode();
    if (idx == -1) { cout << "No space\n"; return; }
    dataArr[idx] = val;
    nextArr[idx] = head;
    head = idx;
}


void printList() {
    int curr = head;
    while (curr != -1) {
        cout << dataArr[curr] << " -> ";
        curr = nextArr[curr];
    }
    cout << "NULL\n";
}

int main() {
    init();
    insertHead(10);
    insertHead(20);
    insertHead(30);
    printList(); 
}
