#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;
// 1. 嵌套深度即为栈长度
// 2. 按嵌套深度的奇偶性来区分
// https://leetcode-cn.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solution/javazhan-shi-xian-zuo-ti-wu-fen-zhong-du-ti-liang-/
vector<int> maxDepthAfterSplit(string seq)
{
    vector<int> result(seq.size(), 0);
    // stack<char> sk;
    vector<int> depth(seq.size());
    int i = 0;
    int stackD = 0;
    for (char c : seq)
    {
        if (c == '(')
        {
            // sk.push(c);
            stackD++;
            depth[i] = stackD;
        }
        else
        {
            depth[i] = stackD;
            stackD--;
        }

        i++;
    }
    i = 0;
    for (int d:depth){
        if(d%2==0){
            result[i]=1;
        }
        i++;
    }
    return result;
}