#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(n, 1, k);
        return res;
    }
    void dfs(int target, int begin, int k)
    {
        if (target == 0 && k == 0) {
            res.push_back(path);
        }
        for (int i = begin; i <= 9; i++) {
            if (target - i < 0 || k == 0) {
                return;
            }
            path.push_back(i);
            dfs(target - i, i + 1, k - 1);
            path.pop_back();
        }
    }

private:
    vector<vector<int>> res;
    vector<int> path;
};