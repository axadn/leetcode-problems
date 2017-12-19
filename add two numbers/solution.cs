/**You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {

        bool carry = false;
        ListNode head = new ListNode(0);
        ListNode currentNode = head;

        while(true){
           if(carry) currentNode.val += 1;
            if(l1 != null) currentNode.val += l1.val;
            if(l2 != null) currentNode.val += l2.val;

            if(currentNode.val > 9){
                carry = true;
                currentNode.val = currentNode.val - 10;
            }
            else{
                carry = false;
            }

            if(l1!=null) l1 = l1.next;
            if(l2!=null) l2 = l2.next;
            if(l1 == null && l2 ==null){
                if(carry) currentNode.next = new ListNode(1);
                break;
            }
            else{
                currentNode.next = new ListNode(0);
                currentNode = currentNode.next;
            }
        }
        return head;
    }
}
