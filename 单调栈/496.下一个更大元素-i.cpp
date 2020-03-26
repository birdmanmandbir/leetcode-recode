#include <vector>
#include <stack>
using namespace std;
#include <unordered_map>

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }
            map[nums2[i]]=s.empty()?-1:s.top();
            // 要求的是右边的第一个比 x 大的元素
            s.push(nums2[i]);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
private:
    unordered_map<int,int> map;
};
// @lc code=end

