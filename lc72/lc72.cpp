#include "lib/general.h"
// https://leetcode-cn.com/problems/edit-distance/solution/edit-distance-by-ikaruga/
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        if (m * n == 0)
            return max(m, n);
        vector<vector<int>> dp(m + 1, vector<int>(n + 1)); // m+1 could include empty word
        // initialize dp
        for (int i = 0; i < n + 1; i++) {
            dp[0][i] = i;
        }
        for (int j = 0; j < m + 1; j++) {
            dp[j][0] = j;
        }
        // calculate dp
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                // add and delete corresponding to different direction of movement in the two word
                int addVal = dp[i - 1][j];
                int delVal = dp[i][j - 1];
                int repVal = dp[i - 1][j - 1];
                dp[i][j] = min(repVal, min(addVal, delVal)) + 1;
                // note that i and j relationship with the word; if it is different, you should say it before
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};