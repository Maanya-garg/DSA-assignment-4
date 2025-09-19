#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int match(queue<int> q, stack<int> s) {
    int rotations = 0;  
    while (!q.empty() && rotations < q.size()) {
        if (q.front() == s.top()) {
            q.pop();
            s.pop();
            rotations = 0;
        } else {
            q.push(q.front());
            q.pop();
            rotations++; 
        }
    }
    return q.size(); 
}
int main(){
	 queue<int> q;
    stack<int> s;
    q.push(1);
    q.push(1);
    q.push(0);
	q.push(0);
    s.push(1);
    s.push(0);
    s.push(1);
    s.push(0);
    cout << "Remaining hungry students = " << match(q, s) << endl;
    return 0;
}
