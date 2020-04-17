#include "lib/general.h"
// https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/solution/bu-ke-pai-zhong-de-shun-zi-pai-xu-fang-shi-he-bu-p/
bool isStraight(vector<int>& nums)
{
    // 如果 max - min + 1 < 5, 一定是因为有大小王, 所以 true;
    // 如果有重复， 返回false;
    int maxVal = INT_MIN;
    int minVal = INT_MAX;
    vector<bool> exist(14, false);
    for (int i : nums) {
        if (i == 0)
            continue;
        if (!exist[i]) {
            exist[i] = true;
        } else {
            return false;
        }
        if (i < minVal) {
            minVal = i;
        }
        if (i > maxVal) {
            maxVal = i;
        }
    }
    if (maxVal - minVal + 1 <= 5) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    vector<int> input = { 0, 0, 8, 5, 4 };
    cout << isStraight(input);
}