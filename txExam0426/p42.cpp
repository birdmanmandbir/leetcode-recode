#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    int n;
    cin >> n;
    int peek = -1;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int opa;
            cin >> opa;
            q.push(opa);
        } else if (cmd == "poll") {
            q.pop();
        } else {
            cout << q.front() << endl;
        }
    }
}