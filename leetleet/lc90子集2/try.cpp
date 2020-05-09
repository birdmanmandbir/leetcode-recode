#include <bits/stdc++.h>
using namespace std;
// 此题未通过，暂时不做
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> res;
        res.push_back(vector<int>(0));
        vector<int> tmp;
        set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.find(nums[i])!=st.end()){
                // find it!
                continue;
            }
            int curN = res.size();
            for (int j = 0; j < curN; j++) {
                tmp = vector<int> (res[j]);
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
            st.insert(nums[i]);
        }
        return res;
    }
};

int main(){
    vector<int> input = {1,2,3};
    (new Solution())->subsets(input);
}