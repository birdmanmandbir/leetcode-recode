#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        if (!root)
            return result;
        dfs(root, sum, {});
        return result;
    }
    bool dfs(TreeNode* root, int sum, vector<int> tmpv)
    {
        if (root == NULL && sum != 0)
            return false;
        if (sum - root->val == 0) {
            tmpv.push_back(root->val);
            result.push_back(tmpv);
            return true;
        }
        if (sum - root->val < 0)
            return false;
        if (dfs(root->left, sum - root->val, tmpv) || dfs(root->right, sum - root->val, tmpv)) {
            tmpv.push_back(root->val);
            return true;
        }
        return false;
    }

private:
    vector<vector<int>> result;
};
TreeNode* readATree(vector<int> input){
    TreeNode* root = new TreeNode(input[0]);
}