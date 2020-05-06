#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        visited = vector<bool> (nums.size());
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int>& nums, int begin){
        if (path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for (int i = 0; i<nums.size(); i++){
            if (visited[i]) {
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = true;
            dfs(nums, i);
            path.pop_back();
            visited[i] = false;
        }
    }
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> visited;
};