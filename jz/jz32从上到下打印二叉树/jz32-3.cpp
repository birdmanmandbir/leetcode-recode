#include "../lib/general.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/solution/cli-yong-dequeshuang-duan-dui-lie-hao-shi-0ms-ji-b/
// 前取后放，后取前放
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == NULL)
            return vector<vector<int>>();
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool flag = true;
        vector<vector<int>> res;
        while (!dq.empty()) {
            // print this level
            int n = dq.size();
            vector<int> tmp;
            while (n > 0) {
                TreeNode* node;
                if (flag) {
                    node = dq.front();
                    dq.pop_front();
                    if(node->left)dq.push_back(node->left);
                    if(node->right)dq.push_back(node->right);
                } else {
                    node = dq.back();
                    dq.pop_back();
                    if(node->right)dq.push_front(node->right);
                    if(node->left)dq.push_front(node->left);
                }
                tmp.push_back(node->val);
                n--;
            }
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }
};