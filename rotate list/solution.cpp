/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/** 
We can use the two-pointers approach to get the element at list.length - 1 - k
If our runner reaches the end before we get to listLength - 1 - k,
we can call rotate right again with k becoming k mod listLength 
**/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        ListNode * end = head;
        for(int i = 0; i < k; ++i){
            if(end == NULL){
                return rotateRight(head, k % i);
            }
            end = end->next;
        }
        if(end == NULL || end == head) return head;
        
        ListNode* begin = head;
        while(end ->next !=NULL){
            end = end->next;
            begin = begin->next;
        }
        
        ListNode* newHead = begin->next;
        begin->next = NULL;
        end->next = head;
        return newHead;  
    }
};