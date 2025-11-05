#include <iostream>
using namespace std;

#define SIZE 5

int queueArr[SIZE];
int front = -1;
int rear = -1;


bool isEmpty() {
    return (front == -1);
}


bool isFull() {
    return (rear == SIZE - 1);
}


void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is Full!" << endl;
        return;
    }
    if (front == -1) {
        front = 0; 
    }
    rear++;
    queueArr[rear] = value;
    cout << value << " inserted into the queue." << endl;
}


void dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << queueArr[front] << " removed from the queue." << endl;
    front++;
    if (front > rear) {
        front = rear = -1; 
    }
}


void display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queueArr[i] << " ";
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
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
