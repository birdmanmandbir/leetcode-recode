#include <bits/stdc++.h>
using namespace std;

stack<pair<int, string>> stk;


void appendCommand(string& a, string& b, bool needPush)
{
    a += b;
    if (needPush) stk.push({2, b});
}

void deleteCommand(string& a, int k, bool needPush)
{
    if (needPush) stk.push({1, a.substr(a.size() - k,k)});
    a.erase(a.begin() + a.size() - k, a.end());
}

char getKCommmand(string& a, int i)
{
    return a[i - 1];
}

// 当删除时，应该将它的逆命令存入栈

int main()
{
    std::ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string s;
    int cmd;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> cmd;
        switch (cmd) {
        case 1:
            cin >> tmp;
            appendCommand(s, tmp, true);
            break;
        case 2:
            int k;
            cin >> k;
            deleteCommand(s, k, true);
            break;
        case 3:
            int i;
            cin >> i;
            if (i > s.size()){
                break;
            }
            cout << getKCommmand(s, i) << endl;
            break;
        case 4:
            auto revCmdPair = stk.top();
            int cmd = revCmdPair.first;
            string ope = revCmdPair.second;
            if (cmd==1){
                appendCommand(s, ope, false);
            }else{
                deleteCommand(s, ope.size(), false);
            }
            stk.pop();
        }
    }
}