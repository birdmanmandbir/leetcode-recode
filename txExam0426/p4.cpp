#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> sk1;
    stack<int> sk2;
    int n;
    cin >> n;
    int peek = INT_MIN;
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int opa;
            cin >> opa;
            if (sk1.empty()){
                peek = opa;
            }
            sk1.push(opa);
        } else if (cmd == "poll") {
            if (!sk2.empty()) {
                sk2.pop();
            } else {
                while (!sk1.empty()) {
                    sk2.push(sk1.top());
                    sk1.pop();
                }
                sk2.pop();
            }
            if (sk1.empty() && sk2.empty()){
                peek = INT_MIN;
            }
        } else {
            if (!sk2.empty()) {
                cout << sk2.top() << endl;
            } else {
                cout << peek << endl;
            }
        }
    }
}