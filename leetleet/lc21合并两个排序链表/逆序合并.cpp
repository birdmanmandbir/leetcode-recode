#include "/home/neil/Codes/leetcode/lib/general.h"

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* res = NULL;
        ListNode* cur1N;
        ListNode* cur2N;

        while (cur1 && cur2) {
            cur1N = cur1->next;
            cur2N = cur2->next;
            if (cur1->val < cur2->val) {
                cur1->next = res;
                res = cur1;
                cur1 = cur1N;
            } else {
                cur2->next = res;
                res = cur2;
                cur2 = cur2N;
            }
        }
        while (cur1) {
            cur1N = cur1->next;
            cur1->next = res;
            res = cur1;
            cur1 = cur1N;
        }
        while (cur2) {
            cur2N = cur2->next;
            cur2->next = res;
            res = cur2;
            cur2 = cur2N;
        }
        return res;
    }
};
ListNode* getLinkedList(vector<int> a, int n)
{
    ListNode* head = new ListNode(-1);
    ListNode* tmp = head;
    for (int i = 0; i < n; i++) {
        tmp->val = a[i];
        tmp->next = i == n - 1 ? NULL : new ListNode(-1);
        tmp = tmp->next;
    }
    return head;
}
void printLinkedList(ListNode* l1)
{
    std::cout << "[";
    ListNode* tmp = l1;
    while (tmp != NULL) {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << "]\n";
}
int main()
{
    vector<int> a = { 1, 2, 4 };
    vector<int> b = { 1, 3, 4 };
    ListNode* aa = getLinkedList(a, 3);
    ListNode* bb = getLinkedList(b, 3);
    ListNode* cc = (new Solution())->mergeTwoLists(aa, bb);
    printLinkedList(cc);
}