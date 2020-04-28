// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // 本质上是单增区间高度的和， 高度 = max - min
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i]>prices[i-1]){
                res+=prices[i]-prices[i-1];
            }
        }
        return res;
    }
};

int main()
{
    vector<int> input = {7,1,5,3,6,4};
    cout << (new Solution())->maxProfit(input);
}