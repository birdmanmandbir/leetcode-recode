#include <vector>
#include <math.h>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 * Accepted
 * 24/24 cases passed (96 ms)
 * Your runtime beats 7.46 % of cpp submissions
 * Your memory usage beats 5.23 % of cpp submissions (9.3 MB)
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // if without this, there will be: "pointer index expression with base
        // 0x000000000000 overflowed to 0xfffffffffffffffc (stl_vector.h)"
        if(n==0)return 0;
        vector<int> dp(nums.size(),1);
        // for(int i=0;i<nums.size();i++){
        //     dp[i]=1;
        // }
        int result=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
                result=max(result, dp[i]);
            }
        }
        return result;
    }
};
// @lc code=end

int main(){
    // vector<int> v={1,3,6,7,9,4,10,5,6};
    vector<int> v={1,3,4,4};
    int result = (new Solution())->lengthOfLIS(v);
    cout<<result<<"\n";
}