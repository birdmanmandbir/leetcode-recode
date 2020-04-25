#include "/home/neil/Codes/leetcode/lib/general.h"

class Solution {
public:
string reverseWords(string s)
{
    if (s.size() == 0)
        return "";
    bool isAllSpace = true;
    for (char c : s) {
        if(c!=' '){
            isAllSpace = false;
        }
    }
    if(isAllSpace)return "";
    stack<string> stk;
    string tmps;
    bool findBegin = false;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != ' ') {
            if (!findBegin) {
                findBegin = true;
            }
            tmps += c;
            if (i == s.size() - 1) {
                stk.push(tmps);
                tmps = "";
                findBegin = false;
            }
        } else if (findBegin) {
            stk.push(tmps);
            tmps = "";
            findBegin = false;
        }
    }
    string res;
    while (!stk.empty()) {
        res += stk.top();
        res += " ";
        stk.pop();
    }
    res.erase(res.size() - 1);
    return res;
}
};