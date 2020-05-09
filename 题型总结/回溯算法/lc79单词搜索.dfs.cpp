#include <bits/stdc++.h>
using namespace std;
// @回溯算法
class Solution {
public:
    // https://leetcode-cn.com/problems/word-search/solution/cdfsdi-gui-hui-su-by-lorwin/
    // tips：dfs函数用实参，不要用形参，不然效率差10倍（时间and空间） 【原理：实参传递的是指针或引用】
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="")return false;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                // 因为所有点都可以作为起始点，所以对每个点进行dfs
                if(dfs(board, word, i, j, 0))return true;
            }
        }
        return false;
    }
    // k is index in word
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k){
        int m=board.size();
        int n=board[0].size();
        if(i<0||i>=m||j<0||j>=n)return false;
        if(board[i][j]!=word[k])return false;
        if(k==word.size()-1)return true;
        // 保证仅递归时此处标记为'/'
        char tmp=board[i][j];
        board[i][j]='/';
        bool res=dfs(board, word, i+1, j, k+1)||
            dfs(board, word, i-1, j, k+1)||
            dfs(board, word, i, j+1, k+1)||
            dfs(board, word, i, j-1, k+1);
        board[i][j]=tmp;
        return res;
    }
};