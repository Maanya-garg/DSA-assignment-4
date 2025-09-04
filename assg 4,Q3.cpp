#include <iostream>
using namespace std;
#define MAX 100
int queue[MAX];
int front = -1;
int rear = -1;
bool isEmpty() {
    return (front == -1 || front > rear);
}

bool isFull() {
    return (rear == MAX - 1);}
void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full." << endl;
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return -1; 
    }
    int item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return item;
}
int size() {
    if (isEmpty()) return 0;
    return rear - front + 1;
}
void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}
void interleaveQueue() {
    int n = size();
    if (n == 0) {
        cout << "Queue is empty." << endl;
        return;
    }
    int half = n / 2;
    int firstHalf[half + (n % 2)];   
    int secondHalf[half];
    for (int i = 0; i < half + (n % 2); i++) {
        firstHalf[i] = dequeue();
    }
    for (int i = 0; i < half; i++) {
        secondHalf[i] = dequeue();
    }
    int i = 0, j = 0;
    while (i < half + (n % 2) && j < half) {
        enqueue(firstHalf[i++]);
        enqueue(secondHalf[j++]);
    }
    while (i < half + (n % 2)) {
        enqueue(firstHalf[i++]);
    }
    front = 0;
    rear = n - 1;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        enqueue(x);
    }
    cout << "Original queue: ";
    display();
    interleaveQueue();
    cout << "Interleaved queue: ";
    display();
    return 0;
}
