#include <string>
#include <stack>
#include <iostream>
using namespace std;
string reverseWords(string s)
{
    stack<char> st;
    string result;
    for (char c : s)
    {
        if (c != ' ')
        {
            st.push(c);
        }
        else
        {
            while (!st.empty())
            {
                result += st.top();
                st.pop();
            }
            result += c;
        }
    }
    // 注意最后一个位置没有空格, 所以会在栈不为空的情况结束for循环
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
int main()
{
    cout << reverseWords("Let's take LeetCode contest") << endl;
}