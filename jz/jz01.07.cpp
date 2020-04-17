// 旋转矩阵
// 解法3： 利用矩阵旋转一次 = 先上下翻转再沿正对角线反转
// https://leetcode-cn.com/problems/rotate-matrix-lcci/solution/xuan-zhuan-ju-zhen-by-leetcode-solution/
#include "lib/general.h"
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int N = matrix.size();
        // up and down
        for (int i = 0; i < N / 2; i++) {
            for (int j = 0; j < N; j++) {
                swap(matrix[i][j], matrix[N - i - 1][j]);
            }
        }
        // positive orthogonal
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};