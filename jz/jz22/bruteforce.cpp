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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        vector<ListNode*> v;
        ListNode* cur=head;
        while(cur!=NULL){
            v.push_back(cur);
            cur=cur->next;
        }
        int index=v.size()-k;
        return v[index];
    }
};