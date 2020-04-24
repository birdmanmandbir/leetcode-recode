#include "lib/general.h"
// https://leetcode-cn.com/problems/sliding-window-maximum/solution/shuang-xiang-dui-lie-jie-jue-hua-dong-chuang-kou-z/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() == 0)return {};
        vector<int> res;
        deque<int> window;
        // initial window with first k numbers (store index in the window?)
        // 很巧妙, 如果最大值在最前面, 那么pop时可保证第二大和第三大还在deque种
        // 如果最大值在后面, 则不会优先被pop
        // 存index是为了保证在移动窗口时删除不属于区间中的front
        for (int i=0;i<k;i++){
            while (!window.empty() && nums[i] > nums[window.back()]){
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);
        // start to move window
        for (int i = k;i < nums.size();i++){
            if (!window.empty() && window.front()<=i-k){
                window.pop_front();
            }
            while (!window.empty() && nums[i] > nums[window.back()]){
                window.pop_back();
            }
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        return res;
    }
};