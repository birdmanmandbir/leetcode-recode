#include "lib/general.h"
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        priority_queue<int> pq;
        int i = 0;
        int n = arr.size();
        if (k == 0) return vector<int>();
        while (i < n) {
            if (pq.size() < k) {
                pq.push(arr[i]);
            }else{
                if (pq.top()>arr[i]){
                    pq.pop();
                    pq.push(arr[i]);
                }
            }
            i++;
        }
        // pop results;
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};