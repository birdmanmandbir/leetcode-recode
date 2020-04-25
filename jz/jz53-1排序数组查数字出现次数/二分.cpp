#include "/home/neil/Codes/leetcode/lib/general.h"
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/zai-pai-xu-shu-zu-zhong-cha-zhao-yuan-su-de-di-yi-/
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.size() == 0){
            return 0;
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
        if (leftBound == -1)return 0;
        return rightBound - leftBound + 1;
    }
};

int main(){
    vector<int> input = {1,2,2,2,3};
    (new Solution())->search(input,2);
}