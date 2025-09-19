#include <iostream>
#include <queue>
#include <stack>
using namespace std;
bool checkSorted(queue<int>& q1, queue<int>& q2) {
    stack<int> s;
    int expected = 1;
    int n = q1.size();
    while (!q1.empty()) {
        int front = q1.front();
        q1.pop();
        if (front == expected) {
            q2.push(front); 
            expected++;
        } else {
            if (!s.empty() && s.top() < front) {
                return false; 
            }
            s.push(front);
        }
        while (!s.empty() && s.top() == expected) {
            q2.push(s.top());
            s.pop();
            expected++;
        }
    }
    while (!s.empty()) {
        if (s.top() != expected) return false;
        q2.push(s.top());
        s.pop();
        expected++;
    }
    return (expected - 1 == n);
}
int main() {
    queue<int> q1;
    queue<int> q2; 
    q1.push(5);
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    if (checkSorted(q1, q2)) {
        cout << "Yes\nSorted Queue: ";
        while (!q2.empty()) {
            cout << q2.front() << " ";
            q2.pop();
        }
    } else {
        cout << "No\n";
    }
    return 0;
}
