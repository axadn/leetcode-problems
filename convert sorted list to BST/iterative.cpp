/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
Basic approach:
   set pointer to beginning
   Continually split range of indices into two leftwise, 
    pushing onto a stack
    stop when our range length is 0 
    split the right range in the same fashion (leftwise) to get the right child

    We are treating the list like an inorder traversal
    
    Time complexity of this algorithm is O(n). Storage space is O(log n)
**/
struct stackFrame{
    bool leftVisited, rightVisited;
    int rangeStart, rangeEnd;
    TreeNode* node;
        stackFrame(int rangeStart, int rangeEnd): rangeStart(rangeStart), rangeEnd(rangeEnd){
            leftVisited = false;
            rightVisited = false;
            node = NULL;
        }
        stackFrame(){}
};
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* current = head;
        stack<stackFrame *> stack;
        int length = getListLength(head);
        stack.push(new stackFrame(0,length - 1));
        TreeNode* tempNode;
        TreeNode* root;
        stackFrame* top;
        int mid;
        while(!stack.empty()){
            top = stack.top();
            mid = (top->rangeStart + top->rangeEnd + 1)/ 2;
            if(!top->leftVisited){
                top->leftVisited = true;
                if(top->rangeStart == mid){
                    root = new TreeNode(current->val);
                    current = current->next;
                    delete top;
                    stack.pop();
                }
                else{
                    stack.push(new stackFrame(top->rangeStart, mid - 1));
                }  
            }else if(!top->rightVisited){
                top->rightVisited = true;
                top->node = new TreeNode(current->val);
                current = current->next;
                top->node->left = root;
                if(mid >= top->rangeEnd){
                    root = NULL;
                }else{
                    stack.push(new stackFrame(mid + 1, top->rangeEnd));
                }
            }
            else{
                top->node->right = root;
                root = top->node;
                delete top;
                stack.pop();
            }
        }
        return root;
    }
    int getListLength(ListNode* head){
        if(head == NULL) return 0;
        ListNode* current = head;
        int  count = 1;
        while(current->next != NULL){ current = current->next; ++count;}
        return count;
    }
};