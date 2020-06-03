#include <bits/stdc++.h>
using namespace std;
// 90% 90还差一个判断长度的，长度要求小于8😫

unordered_map<char, int> howMuchDup(string s)
{
    unordered_map<char, int> m;
    int result = 0;
    for (auto c : s) {
        if (m.find(c) == m.end()) {
            m[c] = 1;
        } else {
            m[c]++;
        }
    }
    return m;
}

bool isDup(string s)
{
    set<char> st;
    for (auto c : s) {
        if (st.find(c) == st.end()) {
            st.insert(c);
        } else {
            return true;
        }
    }
    return false;
}

int stepMult(int length)
{
    if (length == 1) {
        return 1;
    }
    return length * stepMult(length - 1);
}

int main()
{
    string input;
    cin >> input;
    int n = input.size();
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int stmul = stepMult(n);
    if (!isDup(input)) {
        cout << stmul << endl;
    } else {
        unordered_map<char, int> m = howMuchDup(input);
        for (auto it = m.begin(); it != m.end(); it++) {
            stmul /= stepMult((*it).second);
        }
        cout << stmul << endl;
    }
}