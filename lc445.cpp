#include "lib/general.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        stack<int> stk1;
        stack<int> stk2;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 != NULL) {
            stk1.push(cur1->val);
            cur1 = cur1->next;
        }
        while (cur2 != NULL) {
            stk2.push(cur2->val);
            cur2 = cur2->next;
        }
        int carry = 0;
        ListNode* res = NULL; // 如果不置为null则值不确定，会报错
        while (!stk1.empty() || !stk2.empty() || carry != 0) {
            int a = stk1.empty() ? 0 : stk1.top();
            int b = stk2.empty() ? 0 : stk2.top();
            if (!stk1.empty())
                stk1.pop();
            if (!stk2.empty())
                stk2.pop();
            int addAB = a + b + carry;
            int curVal = addAB % 10;
            carry = addAB >= 10 ? 1 : 0;
            // 添加到链表头
            ListNode* cur = new ListNode(curVal);
            cur->next = res;
            res = cur;
        }
        return res;
    }
};