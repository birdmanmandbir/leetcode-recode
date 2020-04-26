#include "../lib/general.h"
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        if (nums.size() == k)
            return nums;
        unordered_map<int, int> map; // num:freq
        for (auto& x : nums) {
            if (map.find(x) == map.end()) {
                map[x] = 1;
            } else {
                map[x]++;
            }
        }
        // build min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto x : map) {
            if (k <= pq.size()) {
                // be careful!! (second: first) when push into pq;
                if (x.second > pq.top().first) {
                    pq.pop();
                    pq.push({ x.second, x.first });
                }
            } else {
                pq.push({ x.second, x.first });
            }
        }
        // get result
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};