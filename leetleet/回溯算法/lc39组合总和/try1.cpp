// https://leetcode-cn.com/problems/combination-sum/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-2/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int begin){
        int n = candidates.size();
        if (target == 0){
            res.push_back(path);
            return;
        }
        for (int i = begin; i < n; i++){
            if (target - candidates[i] < 0){
                // 剪枝
                return;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i); // 因为数字可以重复，所以begin为i
            path.pop_back();
        }

    }
private:
    vector<vector<int>> res;
    vector<int> path;
};