#include "../lib/general.h"
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
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* result = new ListNode(-1);
        ListNode* cur3 = result;
        int carry = 0;
        while (1) {
            int curA = cur1 != NULL ? cur1->val : 0;
            int curB = cur2 != NULL ? cur2->val : 0;
            int addAB = curA + curB + carry;
            int curVal = addAB % 10;
            cur3 -> val = curVal;
            if (addAB >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            // termination condition 1; cur position:
            if (cur1 == NULL && cur2 == NULL) {
                cur3->next = NULL;
                return result;
            }
            // prepare next beginning value
            cur1 = cur1 != NULL ? cur1->next : NULL;
            cur2 = cur2 != NULL ? cur2->next : NULL;
            // termination condition 2; next position:
            if (cur1 == NULL && cur2 == NULL && carry == 0) {
                cur3->next = NULL;
                return result;
            }
            // prepare next cur3
            // with 2 termination condition, if we create new listnode,
            // we ensure that it can be assign a value;
            cur3 -> next = new ListNode(-1);
            cur3 = cur3->next;
        }
    }
};











ListNode *getLinkedList(int *a, int n)
{
    ListNode *head = new ListNode(-1);
    ListNode *tmp = head;
    for (int i = 0; i < n; i++)
    {
        tmp->val = a[i];
        tmp->next = i == n - 1 ? NULL : new ListNode(-1);
        tmp = tmp->next;
    }
    return head;
}
void printLinkedList(ListNode *l1)
{
    std::cout << "[";
    ListNode *tmp = l1;
    while (tmp != NULL)
    {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    cout << "]\n";
}
int main()
{
    int a[] = {2, 4, 3};
    ListNode *l1 = getLinkedList(a, sizeof(a) / 4);
    printLinkedList(l1);
    int b[] = {5, 6, 4};
    ListNode *l2 = getLinkedList(b, sizeof(b) / 4);
    printLinkedList(l2);

    ListNode *result = (new Solution())->addTwoNumbers(l1, l2);
    printLinkedList(result);
}