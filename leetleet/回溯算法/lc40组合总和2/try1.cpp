// https://leetcode-cn.com/problems/combination-sum-ii/solution/hui-su-suan-fa-jian-zhi-python-dai-ma-java-dai-m-3/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return res;
    }
    void dfs(vector<int>& candidates, int target, int begin)
    {
        int n = candidates.size();
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < n; i++) {
            if (target - candidates[i] < 0) {
                // 剪枝
                return;
            }
            if (i>begin && candidates[i] == candidates[i-1]){
                // 剪枝，相同的candidates只有第一个有资格进入递归，递归时则可以遍历到后面的相同candidates
                continue;
            }
            path.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i+1);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};

int main(){
    vector<int> input = {1,1,1};
    (new Solution())->combinationSum2(input, 3);
}