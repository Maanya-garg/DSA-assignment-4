#include <iostream>
#include <queue>
using namespace std;
queue<char> q;
int freq[256] = {0};
char processChar(char ch) {
    freq[(int)ch]++;
    q.push(ch);
    while (!q.empty() && freq[(int)q.front()] > 1) {
        q.pop();
    }
    if (!q.empty())
        return q.front();
    else
        return -1;
}
int main() {
    cout << "Enter characters separated by spaces (press Enter when done): ";
    char ch;
    while (cin >> ch) {
        char firstNonRepeating = processChar(ch);
        if (firstNonRepeating == -1)
            cout << -1 << " ";
        else
            cout << firstNonRepeating << " ";
        if (cin.peek() == '\n') break;
    }
    cout << endl;
    return 0;
}
