#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for  (auto x:nums){
            res ^= x;
        }
        int h = 1;
        while ((h&res) == 0){
            h = h << 1;
        }
        int a = 0;
        int b = 0;
        for (auto x:nums){
            if ((x^h)==0){
                a ^= x;
            }else {
                b ^= x;
            }
        }
        vector<int> resultv;
        resultv.push_back(a);
        resultv.push_back(b);
        return resultv;
    }
};

int main(){
    vector<int> input = {4,1,4,6};
    (new Solution())->singleNumbers(input);
}