#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

bool isEmpty() {
    return (front == nullptr);
}

void enqueue(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (isEmpty()) {
        front = rear = newNode;
        newNode->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    cout << value << " inserted into the queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    Node* temp = front;
    int value = temp->data;
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
        rear->next = front;
    }
    delete temp;
    cout << value << " removed from the queue." << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    Node* temp = front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
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
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}

