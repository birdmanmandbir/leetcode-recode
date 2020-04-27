#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, Q;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> Q;
        queue<int> q;
        for (int j = 0; j < Q; j++) {
            string cmd;
            cin >> cmd;
            if (cmd == "TOP") {
                if (q.empty()) {
                    cout << -1 << endl;
                } else {
                    cout << q.front() << endl;
                }
                fflush(stdout);
            } else if (cmd == "PUSH") {
                int opa;
                cin >> opa;
                q.push(opa);
            } else if (cmd == "POP") {
                if (q.empty()) {
                    cout << -1 << endl;
                } else {
                    q.pop();
                }
                fflush(stdout);
            } else if (cmd == "SIZE"){
                cout << q.size() << endl;
            } else {
                q = queue<int> ();
            }
        }
    }
}