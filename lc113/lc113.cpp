#include <iostream>
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
    // final result is the array, so bool is not needed
    // Because Sum could < 0, there should not be `sum - root->val < 0` in code
    // Because node->val could be negative, so should not end when `sum * (sum - root->val) < 0`
    void dfs(TreeNode* root, int sum, vector<int> tmpv)
    {
        if (root == NULL)
            return;
        tmpv.push_back(root->val);
        if (sum - root->val == 0 && !root->right && !root->left) {
            result.push_back(tmpv);
            return;
        }
        dfs(root->left, sum - root->val, tmpv);
        dfs(root->right, sum - root->val, tmpv);
        return;
    }

private:
    vector<vector<int>> result;
};
// Function to insert nodes in level order
TreeNode* insertLevelOrder(vector<int> arr, TreeNode* root, int i, int n)
{
    // Base case for recursion
    if (i < n) {
        if (arr[i] == -1) {
            root = NULL;
            return root;
        }
        TreeNode* temp = new TreeNode(arr[i]);
        root = temp;
        // insert left child
        root->left = insertLevelOrder(arr,
            root->left, 2 * i + 1, n);
        // insert right child
        root->right = insertLevelOrder(arr,
            root->right, 2 * i + 2, n);
    }
    return root;
}
int main()
{
    // vector<int> treeArray = { 5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1 };
    vector<int> treeArray = { -2, -1, -3 };
    TreeNode* root;
    root = insertLevelOrder(treeArray, root, 0, treeArray.size());
    int sum = -5;
    Solution().pathSum(root, sum);
}
// 5 4 8 11 -1 13 4 7 2 -1 -1 5 1 -1 -1 -1 -1 -1 -1 -1 -1
// 22