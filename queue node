#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool isEmpty() {
    return (front == NULL);
}

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = front;
    cout << front->data << endl;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
