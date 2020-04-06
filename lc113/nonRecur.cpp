#include <iostream>
#include <stack>
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
// https://leetcode-cn.com/problems/path-sum-ii/solution/hou-xu-bian-li-qiu-lu-jing-zong-he-by-watson-14/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        vector<vector<int>> result;
        vector<int> tmpv;
        if (!root)
            return result;

        stack<TreeNode*> stk;
        TreeNode* prev = nullptr; // 用于后序遍历防止重复访问节点, 因为根节点未弹出，再次回到根节点时可能会重复的将右节点再加入
        // if root is not null or stk is not empty
        while (root || !stk.empty()) {
            // recur left child
            while (root) {
                stk.push(root);
                tmpv.push_back(root->val);
                sum -= root->val;
                root = root->left;
            }
            // left to leaf
            root = stk.top();
            if (sum == 0 && !root->left && !root->right) {
                // one valid solution
                result.push_back(tmpv);
            }

            // judge whether root->right is valid
            if (!root->right || root->right == prev) {
                stk.pop();
                sum += root->val;
                tmpv.pop_back();
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return result;
    }
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
    vector<int> treeArray = { 5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, 5, 1 };
    // vector<int> treeArray = { -2, -1, -3 };
    TreeNode* root;
    root = insertLevelOrder(treeArray, root, 0, treeArray.size());
    int sum = 22;
    Solution().pathSum(root, sum);
}