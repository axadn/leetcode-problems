/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//O(n) time with constant extra space
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* currentTail;
        ListNode* pairA;
        ListNode* pairB;
        ListNode* next;

        pairA = head;
        pairB = pairA->next;
        
        head = pairB;
        currentTail = pairA;
        next = pairB->next;
        pairB->next = pairA;
        
        while(next != NULL){
            pairA = next;
            pairB = pairA->next;
            
            if(pairB == NULL){
                currentTail->next = pairA;
                currentTail = pairA;
                next = NULL; 
            }else{
                currentTail->next = pairB;
                next = pairB->next;
                pairB->next = pairA;
                currentTail = pairA;
            }
        }
        
        currentTail->next = NULL;
        return head;  
    }
};