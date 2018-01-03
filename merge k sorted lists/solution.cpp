/**
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**my solution using a heap of size k**/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        if(!lists.empty()){
            ListNode* tail = head;
            std::vector<ListNode*> heap = std::vector<ListNode*>();
            for(std::vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); ++it){
                if(*it!= NULL){
                    heap.push_back(*it);
                }
            }
            if(!heap.empty()){
                std::make_heap(heap.begin(), heap.end(), compareNodes);
                std::pop_heap(heap.begin(), heap.end(), compareNodes);
                head = heap.back();
                tail = head;
                heap.pop_back();
                if(tail->next != NULL){
                    heap.push_back(tail->next);
                    std::push_heap(heap.begin(), heap.end(), compareNodes);
                }

                while(!heap.empty()){
                    std::pop_heap(heap.begin(), heap.end(), compareNodes);
                    tail->next = heap.back();
                    tail = tail -> next;
                    heap.pop_back();
                    if(tail->next != NULL){
                        heap.push_back(tail->next);
                        std::push_heap(heap.begin(), heap.end(), compareNodes);
                    }
                }
            }
        }
        return head;
    }
    static bool compareNodes(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
