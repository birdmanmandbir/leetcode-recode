#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        res.push_back(vector<int>(0));
        vector<int> tmp;
        for (int i = 0; i < nums.size(); i++) {
            int curN = res.size();
            for (int j = 0; j < curN; j++) {
                tmp = vector<int> (res[j]);
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};

int main(){
    vector<int> input = {1,2,3};
    (new Solution())->subsets(input);
}