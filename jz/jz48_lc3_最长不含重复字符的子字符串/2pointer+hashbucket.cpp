#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
// 由于字符数量有限, 可以通过asc映射到数组来求解, 比hashmap快4倍
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/
int lengthOfLongestSubstring(string s)
{
    if (s.size() <= 1)
        return s.size();
    // [a, b)
    int a = 0;
    int b = 0;
    int n = s.size();
    int max_length(0);
    vector<int> map(128,-1);
    // unordered_map<char, int> map;
    while (a < n && b < n)
    {
        if (map[s[b]] == -1 || map[s[b]] < a)
        {
            // 没找到;找到但不在窗口中
        }
        else
        {
            // 找到且在窗口中
            a = map[s[b]] + 1;
        }
        // 找到没找到都要更新b的位置;
        // 如果找到了且在窗口中, a的位置已经更新所以s[b]的位置也要更新
        map[s[b]] = b;
        b++;
        // 如果是新字符, 长度理应+1, 所以在b++后更新length
        // 如果是旧字符, a的位置就要更新, 此时b原来的位置肯定属于不重复的区间, b更新位置后再计算length是正确的
        max_length = max(max_length, b - a);
    }
    return max(max_length, b - a);
}