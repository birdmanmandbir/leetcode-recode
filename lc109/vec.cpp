#include "../lib/general.h"
// 如果是双向链表, 快慢指针找到root后其中的两个指针一个指向左, 一个指向右, 递归得到结果后返回root
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head)
    {
        ltv = listToVec(head);
        return buildBST(0, ltv.size());
    }
    TreeNode* buildBST(int l, int r)
    {
        if (l == r)
            return nullptr;
        // find the root
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(ltv[mid]);
        root->left = buildBST(l, mid);
        root->right = buildBST(mid+1, r);
        return root;
    }
    vector<int> listToVec(ListNode* head)
    {
        vector<int> result;
        ListNode* cur = head;
        while (cur != NULL) {
            result.push_back(cur->val);
            cur = cur->next;
        }
        return result;
    }

private:
    vector<int> ltv;
};