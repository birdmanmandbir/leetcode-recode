#include <string>
#include <math.h>
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 此法只能通过1560/1563
// 设计/分析和小样例的计算很重要, 不要忙着做, 想想有没有别的可能
// 此法涉及一些字符串和数字的转换


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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

    }
};
// @lc code=end
ListNode *getLinkedList(int *a, int n)
{
    ListNode *head = new ListNode(-1);
    ListNode *tmp = head;
    for (int i = 0; i < n; i++)
    {
        tmp->val = a[i];
        tmp->next = i==n-1?NULL:new ListNode(-1);
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
        cout<<tmp->val<<",";
        tmp= tmp->next;
    }
    cout<<"]\n";
}
int main(){
    int a[]={9};
    ListNode* l1=getLinkedList(a,sizeof(a)/4);
    printLinkedList(l1);
    int b[]={1,9,9,9,9,9,9,9,9,9};
    ListNode* l2=getLinkedList(b,sizeof(b)/4);
    printLinkedList(l2);

    ListNode* result=(new Solution())->addTwoNumbers(l1,l2);
    printLinkedList(result);
}