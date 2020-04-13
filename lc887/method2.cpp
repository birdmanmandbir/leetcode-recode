#include "../lib/general.h"
// 两个dp, 一个随x递增, 一个随x递减, 那么最大值先增后减, 关键是找到那个单调性变化的点.
//
// key:
// 我们必须保证 鸡蛋碎了之后接下来需要的步数 和 鸡蛋没碎之后接下来需要的步数 二者的 最大值 最小，
// 这样就保证了在 最坏情况下（也就是无论 FF 的值如何） dp(K, N)dp(K,N) 的值最小。
// 如果能理解这一点，也就能理解上面的状态转移方程，即最小化 \max(dp(K-1, X-1), dp(K, N-X))max(dp(K−1,X−1),dp(K,N−X))。

// 链接：https://leetcode-cn.com/problems/super-egg-drop/solution/ji-dan-diao-luo-by-leetcode-solution/
class Solution {
public:
    int superEggDrop(int K, int N) {
        // initial k=1;
        vector<int> dp(N+1);
        for(int i=1;i<=N; i++){
            dp[i] = i;
        }
        // dp will be previous k, and dp2 is cur k;
        // find out other parts of dp
        for (int k=2;k<=K;k++){
            vector<int> dp2(N+1, 0);
            int x = 1; // initial at building 1
            for (int n=1; n<=N;n++){
                while (x<n && max(dp[x-1], dp2[n-x]) > max(dp[x], dp2[n-x-1])){
                    x++;
                }
                dp2[n]=1 + max(dp[x-1], dp2[n-x]);
            }
            dp = dp2;
        }
        return dp[N];
    }
};

int main(){
    cout << (new Solution())->superEggDrop(2,6) << endl;
}