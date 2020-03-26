#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#include <unordered_map>
// 观察数字的结构很重要
/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
vector<int> getArrayFromString(string s)
{
    vector<int> result;
    for (int i = 0; i < s.size(); i++)
    {
        result.push_back((int)s[i] - 48);
    }
    return result;
}
void printVector(vector<int> v)
{
    cout << "[";
    for (int x : v)
    {
        cout << x << ", ";
    }
    cout << "]\n";
}
string reverse(string s, int i)
{
    int left = i;
    int right = s.size() - 1;
    while (left < right)
    {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return s;
}
class Solution
{
public:
    int nextGreaterElement(int n)
    {
        if (n < 10)
            return -1;
        string input = to_string(n);
        int i = input.size() - 2;
        int length = input.size();
        // 寻找需要交换的第一个参数， 并排除单调不升序列
        while (i >= 0 && input[i] >= input[i + 1])
        {
            i--;
        }
        if (i < 0)
        {
            return -1;
        }

        int j = length - 1;
        while (j >= 0 && input[j] <= input[i])
        {
            j--;
        }
        char tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
        input = reverse(input, i + 1);
        try
        {
            return stoi(input);
        }
        catch (exception e)
        {
            return -1;
        }
    }
};
// @lc code=end

int main()
{
    cout << (new Solution())->nextGreaterElement(12443322);
}
// hard input: 11, 230241,12443322,
// 1999..999->large than int, so that need catch exception.