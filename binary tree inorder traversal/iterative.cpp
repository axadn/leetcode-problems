/**
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

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
struct frame{
    TreeNode* node;
    bool didLeft;
    frame(TreeNode* node): node(node), didLeft(false){}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> solution;
        if(root == NULL) return solution;
        stack<frame> stack;
        frame top(root);
        stack.push(top);
        while(!stack.empty()){
            if(!stack.top().didLeft){
                stack.top().didLeft = true;
                if(stack.top().node->left) stack.push(frame(stack.top().node->left));
            }
            else{
                top = stack.top();
                stack.pop();
                solution.push_back(top.node->val);
                if(top.node->right) stack.push(frame(top.node->right));
            }
        }
        return solution;
    }
};
