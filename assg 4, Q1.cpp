#include <iostream>
using namespace std;
# define MAX 4
int queue[MAX];
int front = -1;
int rear = -1;
bool isEmpty() {
    return (front == -1 || front>rear);
}
bool isFull() {
    return (rear == MAX - 1);
}
void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full." << endl;
    } else {
        if (isEmpty()) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
    }
}
void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << queue[front] << endl;
    }
}
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    while (true) {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Empty\n";
        cout << "4. Check if Full\n";
        cout << "5. Peek\n";
        cout << "6. Display Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                if (isFull()) {
                    cout << "Queue is full. Cannot enqueue." << endl;
                } else {
                    int element;
                    cout << "Enter element ";
                    cin >> element;
                    enqueue(element);
                }
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                if (isEmpty())
                    cout << "Queue is empty." << endl;
                else
                    cout << "Queue is not empty." << endl;
                break;
            case 4:
                if (isFull())
                    cout << "Queue is full." << endl;
                else
                    cout << "Queue is not full." << endl;
                break;
            case 5:
                peek();
                break;
            case 6:
                display();
                break;
            case 7:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
        }
    }
}
