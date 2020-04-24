import java.util.ArrayList;

class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}
/*
 * @lc app=leetcode.cn id=19 lang=java
 *
 * [19] 删除链表的倒数第N个节点
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ArrayList<ListNode> al=new ArrayList<>();
        ListNode cur=head;
        while(true){
            al.add(cur);
            cur=cur.next;
            if(cur==null){
                break;
            }
        }
        int total=al.size();
        int pos=total-n+1;
        if(n==total){
            head=head.next;
            return head;
        }
        if(n==1){
            al.get(total-2).next=null;
            return head;
        }
        al.get(pos-2).next=al.get(pos);
        return head;
    }
}
// @lc code=end
