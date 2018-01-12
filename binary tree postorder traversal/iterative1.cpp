/**
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        if(root == NULL) return order;
        stack<std::pair<TreeNode*, bool>>stack;
        stack.push(std::make_pair(root, false));
        TreeNode* top;
        while(!stack.empty()){
            if(stack.top().second){
                order.push_back(stack.top().first->val);
                stack.pop();
            }
            else{
                stack.top().second = true;
                top = stack.top().first;
                if(top->right != NULL){
                    stack.push(std::make_pair(top->right, false));
                }
                if(top->left != NULL){
                     stack.push(std::make_pair(top->left, false));
                }
            }
        }
        return order;
    }
};
