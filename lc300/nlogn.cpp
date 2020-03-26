#include <vector>
#include <math.h>
#include <iostream>
#include <array>
using namespace std;
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 * 24/24 cases passed (4 ms)
 * Your runtime beats 92.04 % of cpp submissions
 * Your memory usage beats 5.23 % of cpp submissions (9.2 MB)
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int> top(nums.size(),0);
        int piles=0;
        for(int i=0;i<n;i++){
            int poker=nums[i];
            int left=0;
            int right=piles;
            // 寻找最左边的位置, left=right时结束
            while(left<right){
                int mid=(left+right)/2;
                // > 说明可以放，继续往左找; < 说明不可以放, left=mid+1.
                // 对于例子[2,2] 因为重复的不算, 所以重复的也应该认为可以放, 这样不会让piles增加
                if(top[mid]>=poker){
                    right=mid;
                }else if(top[mid]<=poker){
                    left=mid+1;
                }
            }
            // 需要判断是否没找到位置, 没找到就要新建一堆; piles是右边开区间, 所以应该在left处放poker
            if(left==piles){
                piles++;
            }
            top[left]=poker;
        }
        return piles;
    }
};
// @lc code=end

int main(){
    // vector<int> v={10,9,2,5,3,7,101,18};
    // vector<int> v={};
    vector<int> v={2,2};
    int result = (new Solution())->lengthOfLIS(v);
    cout<<result<<"\n";
}