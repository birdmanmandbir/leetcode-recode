#include "lib/general.h"
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val)
    {
        val = _val;
        next = NULL;
    }
};

ListNode* reverseList(ListNode* l1)
{
    ListNode* cur = NULL;
    ListNode* prev = l1;
    while (prev) {
        ListNode* prevNext = prev->next;
        prev->next = cur;
        cur = prev;
        prev = prevNext;
    }
    typedef int (*fp)(int);
    fp a[10];

    return cur;
}
