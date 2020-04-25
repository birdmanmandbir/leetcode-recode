#include "/home/neil/Codes/leetcode/lib/general.h"

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> res;
        for (int l = 1, r = 2; l < r;) {
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target){
                vector<int> tmp;
                for (int i = l; i <= r; i++){
                    tmp.emplace_back(i);
                }
                res.emplace_back(tmp);
                l++;
            } else if (sum < target){
                r++;
            } else if (sum > target){
                l++;
            }
        }
        return res;
    }
};

int main(){
    (new Solution())->findContinuousSequence(9);
}