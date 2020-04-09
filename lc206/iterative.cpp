#include "../lib/general.h"
/**
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* cur = NULL;
        ListNode* prev = head;
        while (prev) {
            ListNode* prevNext = prev->next;
            prev->next = cur;
            cur = prev;
            prev = prevNext;
        }
        return cur;
    }
};