#include "../lib/general.h"
// https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/
class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int> res(n);
        int i, j, k;
        i = j = k = 0;
        res[0] = 1;
        for (int p = 1; p < n; p++) {
            int minVal = min(res[i]*2, min(res[j]*3, res[k]*5));
            // don't use else if, because there maybe duplicate value
            if (minVal == res[i]*2){
                res[p] = res[i]*2;
                i++;
            }
            if (minVal == res[j]*3){
                res[p] = res[j]*3;
                j++;
            }
            if (minVal == res[k]*5){
                res[p] = res[k]*5;
                k++;
            }
        }
        return res[n-1];
    }
};

int main(){
    cout << (new Solution())->nthUglyNumber(10) << endl;
}