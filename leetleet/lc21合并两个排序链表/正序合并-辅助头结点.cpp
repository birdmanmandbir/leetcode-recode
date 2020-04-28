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
        ListNode* res = new ListNode(-1);
        ListNode* resCur = res;

        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                resCur->next = cur1;
                resCur = resCur->next;
                cur1 = cur1->next;
            } else {
                resCur->next = cur2;
                resCur = resCur->next;
                cur2 = cur2->next;
            }
        }
        while (cur1) {
            resCur->next = cur1;
            resCur = resCur->next;
            cur1 = cur1->next;
        }
        while (cur2) {
            resCur->next = cur2;
            resCur = resCur->next;
            cur2 = cur2->next;
        }
        return res->next;
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