#include "lib/general.h"
// 简单的递归回溯
// https://leetcode-cn.com/problems/generate-parentheses/solution/gua-hao-sheng-cheng-by-leetcode/
// 遇到边界则新增ans，否则递归两种可能性
// 关键是要新增一个，要么是左括号，要么是右括号，所以需要讨论新增括号的类型和条件
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backTrack(ans, "", 0, 0, n);
        return ans;
    }
    void backTrack(vector<string> &ans, string s, int open, int close, int max){
        if (s.size()==max*2){
            ans.push_back(s);
            return;
        }
        // two possibility
        if (open < max){
            backTrack(ans, s+"(", open+1, close, max);
        }
        if (close < open){
            backTrack(ans, s+")", open, close + 1, max);
        }
        return;
    }
};