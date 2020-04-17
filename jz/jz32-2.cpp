#include "lib/general.h"
// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/solution/cji-bai-100-by-supertiger/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 此题必须保证队列中无NULL, 因为endNode = q.back()
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        TreeNode* endNode = root; //指向每一层最后一个结点
        vector<int> tmpv;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            tmpv.push_back(cur->val);
            if(cur->left)q.push(cur->left);
            if(cur->right)q.push(cur->right);
            if (cur == endNode){
                endNode = q.back();
                res.push_back(tmpv);
                tmpv.clear();
            }
        }
        return res;
    }
};