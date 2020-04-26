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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow, *fast;
        slow = head;
        fast = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (fast == NULL || fast->next == NULL){
            return NULL;
        }
        // 如果链表环之前的一段很长，会导致fast可能提前在环上走了好几圈
        // 证明：https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/java-kuai-man-zhi-zhen-zhao-ru-kou-jie-dian-you-sh/
        // 图：https://leetcode-cn.com/problems/linked-list-cycle-lcci/solution/lian-biao-kuai-man-zhi-zhen-sao-miao-zheng-ming-by/
        slow = head;
        while (slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};