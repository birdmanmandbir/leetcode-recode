#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> res(n);
        res[0] = 1;
        for (int i = 1, interval = 0; i <= k + 1; i++, interval--) {
            res[i - 1] = i % 2 == 1 ? i : k + 1 - kk;
            if (i%2==0)kk++;
        }
        for (int i = k+2; i <= n; i++) {
            res[i - 1] = i;
        }
        return res;
    }
};

int main()
{
    (new Solution())->constructArray(3, 2);
}