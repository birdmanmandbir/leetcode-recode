#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int start = 0;
        int end = 0;
        int pro = 0; //利润初始化为0应付价格一直下跌
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            end = i;
            if (prices[start] > prices[end]) {
                start = end; //遇到价格更低时直接重置买入价格
            }
            int curPro = prices[end] - prices[start];
            pro = max(pro, curPro); //取买入价格重置后的利润与不重置买入价格利润的最大值，排除买入价下降但后续没有较高卖出价导致的利润下降。
            if (end != prices.size() - 1 && prices[end] > prices[end + 1]) {
                res += pro;
                pro = 0;
                start = end;
            }
            if (end == prices.size() - 1) {
                res += pro;
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