/**
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

//my solution without recursion

int const LEFT = 1;
int const RIGHT = -1;
int const ROOT = 0;
int const EMPTY = 2;

struct stackFrame {
    TreeNode* node;
    bool addedChildren;
    int position;
    int inStart;
    int inEnd;
    int postStart;
    int postEnd;
    stackFrame(int position, int inStart, int inEnd, int postStart, int postEnd) : position(position),
        inStart(inStart), inEnd(inEnd), postStart(postStart), postEnd(postEnd), node(NULL), addedChildren(false){}
    stackFrame(): position(EMPTY), node(NULL){}
};
inline int getNumLeft(vector<int> const& inorder, vector<int> const& postorder, int inStart, int inEnd,
                     int postStart, int postEnd){
    for(int i = 0; i <= inEnd - inStart; ++i){
        if(inorder[inStart + i] == postorder[postEnd]) return i;
    }
    return 0;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {     
        stackFrame item;
        stackFrame top;
        int numLeft;
        std::stack<stackFrame> stack;
        if(inorder.size() > 0){
            stack.push(stackFrame(ROOT,0,inorder.size()-1,0,postorder.size()-1));
        }
        else{
            return NULL;
        }
        while(!stack.empty()){
            item = stack.top();
            stack.pop();
            if(item.position != EMPTY && !item.addedChildren){ 
                item.node = new TreeNode(postorder[item.postEnd]);
                if(item.position == RIGHT){
                    top = stack.top();
                    stack.pop();
                    stack.top().node->right = item.node;
                    stack.push(top);
                }
                else if(item.position == LEFT){
                    stack.top().node->left = item.node;
                }
                item.addedChildren = true;
                stack.push(item);
                numLeft = getNumLeft(inorder, postorder, item.inStart, item.inEnd, item.postStart, item.postEnd);
                if(numLeft > 0){
                    stack.push(stackFrame(LEFT, item.inStart, item.inStart + numLeft - 1, item.postStart, item.postStart + numLeft - 1));
                }
                else{
                    stack.push(stackFrame());
                }
                if(item.inStart + numLeft < item.inEnd){
                    stack.push(stackFrame(RIGHT, item.inStart + numLeft + 1, item.inEnd, item.postStart + numLeft, item.postEnd - 1));
                }
                else{
                    stack.push(stackFrame());
                }
            }
        }
        return item.node;
    }
};
