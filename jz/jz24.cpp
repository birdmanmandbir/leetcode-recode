#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
};
ListNode* reverseList(ListNode* head)
{
    if (head == NULL)
        return NULL;
    ListNode* cur = NULL;
    ListNode* pre = head;
    while (pre != NULL) {
        ListNode* preNext = pre->next;
        pre->next = cur;
        cur = pre;
        pre = preNext;
    }
    return cur;
}

int main(){
    ListNode headNode(1);
    ListNode* head = &headNode;
    ListNode* cur = head;
    ListNode a(2);
    ListNode b(3);
    cur->next = &a;
    cur = cur->next;
    cur->next = &b;
    cur = cur->next;
    cur->next = NULL;
    reverseList(head);

}