#include "../lib/general.h"
class Solution {
public:
    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r)
    {
        if (l == r) {
            return 0;
        }
        int mid = l + (r - l) / 2;
        int count = mergeSort(nums, tmp, l, mid) + mergeSort(nums, tmp, mid + 1, r);
        count += mergeAndCount(nums, tmp, l, r);
        return count;
    }
    int mergeAndCount(vector<int>& nums, vector<int>& tmp, int l, int r)
    {
        int count = 0;
        int mid = l + (r - l) / 2;
        int i = l;
        int j = mid + 1;
        int k = l;
        // meaning of tmp?: 暂时存储排序后的结果，最后将tmp复制到nums的相应位置
        // 为什么在i++时更新count？ 因为i++时首次nums[i] <= nums[j], 之前都是nums[i] > nums[j]
        while (i <= mid && j <= r) {
            // must be <= for 13231
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
                count += j - (mid + 1);
            } else {
                tmp[k++] = nums[j++];
            }
        }
        for (int p = i; p <= mid; p++) {
            tmp[k++] = nums[p];
            count += j - (mid + 1);
        }
        for (int p = j; p <= r; p++) {
            tmp[k++] = nums[p];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return count;
    }
    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();
        if (!n){
            return 0;
        }
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n - 1);
    }
};
