#include "lib/general.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 虽然在开头对NULL做了处理，但如果递归时将NULL输入，会导致对于二叉树 [1, 2]， 1 的右子树也被递归而最终结果为 1
// 同时为了防止当两边都为null而overflow，需要处理两边都为null的情况
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right){
            return 1;
        }
        int minD = INT_MAX;
        if(root->left)minD = min(minDepth(root->left), minD);
        if(root->right)minD = min(minDepth(root->right), minD);
        return minD + 1;
    }
};