#include "lib/general.h"
// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/215-by-ikaruga/
int findKthLargest(vector<int>& nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; // 默认是MaxHeap，加greater x>y 后为MinHeap
    for(auto x:nums){
        if(pq.size() == k && x<pq.top()){
            continue;
        }
        pq.push(x);
        if(pq.size()>k){
            pq.pop(); // pop root to make sure pq still with size k
        }
    }
    return pq.top();
}
