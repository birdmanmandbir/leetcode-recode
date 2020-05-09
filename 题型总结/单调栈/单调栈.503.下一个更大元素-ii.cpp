#include <vector>
#include <stack>
#include <iostream>
using namespace std;
#include <unordered_map>
// @单调栈

/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        stack<int> s;
        int n=nums.size();
        // 循环数列， 两倍解决
        for (int i = 2*(nums.size() - 1); i >= 0; i--)
        {
            while (!s.empty() && s.top() <= nums[i%n])
            {
                // 小的就看不见了, 所以pop
                s.pop();
            }
            if (map.find(i%n) == map.end() || map[i%n] == -1)
                map[i%n]=s.empty() ? -1 : s.top();
            // 要求的是右边的第一个比 x 大的元素
            s.push(nums[i%n]);
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=map[i];
        }
        return ans;
    }

private:
    unordered_map<int, int> map;
};

// @lc code=end
int main(){
    vector<int> input={1,2,1};
    (new Solution())->nextGreaterElements(input);
}