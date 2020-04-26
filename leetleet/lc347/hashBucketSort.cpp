#include "../lib/general.h"
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        if (nums.size() == k)return nums;
        unordered_map<int, int> map; // num:freq
        for (auto& x : nums) {
            if (map.find(x) == map.end()) {
                map[x] = 1;
            } else {
                map[x]++;
            }
        }
        // get freq lisr
        int n = nums.size();
        vector<vector<int>> freqV(n+1, vector<int>());
        for (auto i : map) {
            freqV[i.second].push_back(i.first);
        }
        // find result
        vector<int> result;
        for (int i = freqV.size() - 1; i >= 0 && result.size() < k; i--) {
            for (auto x : freqV[i]) {
                if (result.size() < k) {
                    result.push_back(x);
                } else {
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> input={-1,-1};
    (new Solution())->topKFrequent(input, 1);
}