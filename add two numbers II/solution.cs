/**
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        int length1;
        int length2;
        ListNode nodeCounter = l1;
        for(length1 = 0; nodeCounter != null; nodeCounter = nodeCounter.next){length1++;}
        nodeCounter = l2;
        for(length2 = 0; nodeCounter != null; nodeCounter = nodeCounter.next){length2++;}

        if(length1 < length2){
            l1 = pad(l1, length2 - length1);
        }
        else if (length2 < length1) {
            l2 = pad(l2, length1 - length2);
        }
        ListNode result = AddRecur(l1, l2);
        if(result.val >= 10){
            ListNode head = new ListNode(1);
            result.val -= 10;
            head.next = result;
            return head;
        }
        return result;
    }

    public ListNode pad(ListNode list, int numTimes){
        ListNode head = new ListNode(0);
        ListNode tail = head;
        for(int i = 0; i < numTimes - 1; ++i){
            tail.next = new ListNode(0);
            tail = tail.next;
        }
        tail.next = list;
        return head;
    }

    public ListNode AddRecur(ListNode l1, ListNode l2){
        if(l1 == null || l2 == null){
            return null;
        }
        ListNode current = new ListNode(l1.val + l2.val);
        current.next = AddRecur(l1.next,l2.next);
        if(current.next != null && current.next.val >= 10){
            current.next.val -= 10;
            current.val += 1;
        }
        return current;
    }
}
