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
    struct cmp{
        bool operator() (ListNode* a, ListNode* b){
            return a->val < b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (ListNode* l:lists){
            pq.push(l);
        }
        while(!pq.empty()){

        }
    }
    void listPushBack(ListNode*){}
};