#include "../lib/general.h"
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k)
    {
        sort(arr.begin(), arr.end());
        // pop results;
        vector<int> res(k);
        copy(arr.begin(),arr.begin()+k,res.begin());
        return res;
    }
};