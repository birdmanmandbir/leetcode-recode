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
    ListNode* getKthFromEnd(ListNode* head, int k)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        int i = 0;
        while (i < k && fast != NULL) {
            fast = fast->next;
            i++;
        }
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};