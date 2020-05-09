// https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
// 如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
// 可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
// 如果可以一直跳到最后，就成功了。

// 作者：ikaruga
// 链接：https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/

// @贪心

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int farest = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > farest) {
                return false;
            }
            farest = max(farest, i + nums[i]);
            if (farest >= n - 1) {
                return true;
            }
        }
        return true;
    }
};