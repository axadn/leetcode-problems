/**Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* One pass solution */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        for(int i = 0; i < n; ++i){
            current = current->next;    
        }
        if(current == NULL){
            return head->next;
        }
        ListNode* removal = head;
        while(current->next != NULL){
            current = current->next;
            removal = removal->next;
        }
        removal->next = removal->next->next;
        return head;
    }
};