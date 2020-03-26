#include <vector>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> v;
        ListNode* cur=head;
        while(true){
            v.push_back(cur);
            cur=cur->next;
            if(cur==NULL){
                break;
            }
        }
        int total=v.size();
        int pos=total-n+1;
        if(n==total){
            head=head->next;
            return head;
        }
        if(n==1){
            v[total-2]->next=NULL;
            return head;
        }
        v[pos-2]->next=v[pos];
        return head;
    }
};
// @lc code=end
int main(){
    ListNode* head;
    ListNode* cur=head;
    ListNode* next;
    for(int i=1;i<6;i++){
        cur->val=i;
        cur->next=next;
        cur=next;
    }
    next=NULL;
    ListNode* result=new Solution->removeNthFromEnd(head, 2);
}