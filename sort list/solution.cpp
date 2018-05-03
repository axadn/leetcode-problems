/**Sort a linked list in O(n log n) time using constant space complexity.
 * **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/** We should do an iterative merge-sort. A recursive merge-sort would use the call stack, yielding O(log n) space complexity. 
With an iterative approach, we can use constant space complexity. It's a bottom-up approach instead of top-down
**/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode * current = head;
        int listLength = 0;
        while(current != NULL){
            ++listLength;
            current = current->next;
        } 
        int groupSize = 2;
        head = merge(head, 1);

        while(groupSize < listLength){
             head = merge(head, groupSize);
             groupSize *= 2;
         }
    
        return head;
    }
private:
    
    ListNode * merge(ListNode* head, int groupSize){
        ListNode * list2 = head;
        ListNode * list1;
        int list1_index;
        int list2_index;
        ListNode * sectionTail = NULL;
        ListNode * newHead = NULL;
        
        while(list2 != NULL){
            list1 = list2;
            list1_index = 0;
            list2_index = 0;
            for(int i = 0; i < groupSize; ++i){
                list2 = list2->next;
                if(list2 == NULL){
                    if(sectionTail != NULL){
                        sectionTail->next = list1;
                    }
                    if(newHead == NULL){
                        newHead = list1;
                    }
                    return newHead;
                } 
            }
            if(list1->val < list2->val){
                if(sectionTail != NULL) sectionTail->next = list1;
                sectionTail = list1;
                list1_index += 1;
                list1 = list1->next;
            }
            else{
                if(sectionTail != NULL) sectionTail->next = list2;
                sectionTail = list2;
                list2_index += 1;
                list2 = list2->next;
            }
            if (newHead == NULL) newHead = sectionTail;
            while(list1_index < groupSize || (list2 != NULL && list2_index < groupSize)){
                if(list2 != NULL &&
                   (list1_index >= groupSize || (list2_index < groupSize && list2->val < list1->val))){
                    sectionTail->next = list2;
                    sectionTail = list2;

                    list2 = list2->next;
                    ++list2_index;
                }
                else{
                    sectionTail->next = list1;
                    sectionTail = list1;
                    list1 = list1->next;
                    ++list1_index;
                }
            }
        }
        sectionTail->next = NULL;
        return newHead;
    }
};