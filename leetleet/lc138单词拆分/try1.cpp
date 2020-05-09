// https://leetcode-cn.com/problems/word-break/solution/139-by-ikaruga/
// @动态规划
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        size_t validEnd = 0; // 匹配单词的最后一个结尾
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (size_t i = 0; i < s.size(); i++) {
            if (!dp[i]) {
                continue;
                // 因为后面遍历worddict是建立在i之前是valid的状态下
            }
            // dp[i] 表示第 i 个字符前，所有的字符是否可以按字典拆分成单词
            for (auto& word : wordDict) {
                size_t newEnd = i + word.size();
                if (newEnd > s.size()) {
                    continue; // 可能有别的更短的单词
                }
                if (memcmp(&s[i], &word[0], word.size()) == 0) {
                    // FIXME 可能有其它也匹配的单词，所以不在此处结束；但validEnd作用是什么，如何避免选中了使结果不匹配的单词呢？
                    // 样例：san a {"san","s","ana"}
                    dp[newEnd] = true;
                    validEnd = max(validEnd, newEnd);
                }
            }
        }
        return dp.back();
    }
};

int main()
{
    string s = "sana";
    vector<string> wordDict = { "san", "s", "ana" };
    (new Solution())->wordBreak(s, wordDict);
}