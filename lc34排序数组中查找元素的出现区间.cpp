#include "/home/neil/Codes/leetcode/lib/general.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return vector<int> (2, -1);
        }
        int l = 0;
        int r = nums.size() - 1;
        // int mid = l + (r - l) / 2;
        int leftBound(-1), rightBound(-1);
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] == target) {
                r = mid;
            }
        }
        if (nums[l] == target) {
            leftBound = l;
        }
        l = 0;
        r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else if (nums[mid] == target) {
                l = mid;
            }
        }
        if (nums[r] == target) {
            rightBound = r;
        }
        if (leftBound == -1)return vector<int>(2, -1);
        vector<int> res;
        res.push_back(leftBound);
        res.push_back(rightBound);
        return res;
    }
};