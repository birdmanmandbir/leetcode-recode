#include "lib/general.h"
// DFA 有限状态机 <编译器原理>
// https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/
class Solution {
public:
    int getColumn(char c)
    {
        switch (c) {
        case ' ':
            return 0;
        case '+':
            return 1;
        case '-':
            return 1;
        case '.':
            return 3;
        case 'e':
            return 4;
        default:
            if (c <= '9' && c >= '0')
                return 2;
        }
        return -1;
    }

    bool isNumber(string s)
    {
        vector<vector<int>> machine = {
            { 0, 1, 6, 2, -1 },
            { -1, -1, 6, 2, -1 },
            { -1, -1, 3, -1, -1 },
            { 8, -1, 3, -1, 4 },
            { -1, 7, 5, -1, -1 },
            { 8, -1, 5, -1, -1 },
            { 8, -1, 6, 3, 4 },
            { -1, -1, 5, -1, -1 },
            { 8, -1, -1, -1, -1 },
        };
        int state = 0;
        // valid final state will be 1
        vector<int> final = { 0, 0, 0, 1, 0, 1, 1, 0, 1 };
        for (char c : s) {
            int col = getColumn(c);
            if (col < 0 || state < 0)
                return false;
            state = machine[state][col];
        }
        return state>=0 && final[state] > 0;
    }
};
int main(){
    cout <<(new Solution())->isNumber("e") << endl;
}