#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;
// 1. 嵌套深度即为栈长度
// 2. 按嵌套深度的奇偶性来区分
vector<int> maxDepthAfterSplit(string seq)
{
    vector<int> result(seq.size(), 0);
    stack<char> sk;
    vector<int> depth(seq.size());
    int i = 0;
    for (char c : seq)
    {
        if (c == '(')
        {
            sk.push(c);
            depth[i] = sk.size();
        }
        else
        {
            depth[i] = sk.size();
            sk.pop();
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