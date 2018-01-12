/**
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        if(root == NULL) return order;
        stack<TreeNode*> stack;
        stack.push(root);
        TreeNode* top;
        while(!(stack.empty())){
            top = stack.top();
            stack.pop();
            order.push_back(top->val);
            if(top->right != NULL) stack.push(top->right);
            if(top->left != NULL) stack.push(top->left);
        }
        return order;
    }
};


