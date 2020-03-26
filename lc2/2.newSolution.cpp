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

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        ListNode *newl = new ListNode(-1);
        ListNode *tmp3 = newl;
        int carry = 0;
        while (true)
        {
            int curA = tmp1 != NULL ? tmp1->val : 0;
            int curB = tmp2 != NULL ? tmp2->val : 0;
            int addAB = curA + curB + carry;
            int curVal = addAB % 10;
            if (addAB >= 10)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            tmp3->val = curVal;
            // 对于list, 终止条件很重要
            // 如果当前两个数已经都不存在, 说明只有carry, 结果中不会有下一个
            if (tmp1 == NULL && tmp2 == NULL)
            {
                tmp3->next = NULL;
                break;
            }
            tmp1 = tmp1 != NULL ? tmp1->next : NULL;
            tmp2 = tmp2 != NULL ? tmp2->next : NULL;
            // 如果之后不会再有两个相加数, 且carry为0, 结果中不会有下一个
            if (tmp1 == NULL && tmp2 == NULL && carry == 0){
                tmp3 ->next==NULL;
                break;
            }
            tmp3->next = new ListNode(-1);
            tmp3 = tmp3->next;
        }
        return newl;
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