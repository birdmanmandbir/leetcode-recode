#include <unordered_map>
#include <list>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
char leftOf(char c)
{
    if (c == '}')
        return '{';
    if (c == ']')
        return '[';
    if (c == ')')
        return '(';
    return '!';
}

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        int i = 0;
        int n = s.size();
        if(n%2!=0)return false;
        while (i < n)
        {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
            {
                stk.push(s[i]);
            }
            else
            {
                if (!stk.empty() && stk.top() == leftOf(s[i]))
                    stk.pop();
                else
                    return false;
            }
            i++;
        }
        return stk.empty();
    }
};

// @lc code=end
int main(){
    cout<<(new Solution())->isValid("}(")<<"\n";
}