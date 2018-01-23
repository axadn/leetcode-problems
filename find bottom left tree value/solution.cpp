/**
Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.
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
/* my solution using a queue to do a level order traversal 
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> level;
        int nodesInLevel = 1;
        int nodesInNextLevel = 0;
        int nodesConsumed = 0;
        TreeNode * leftMost;
        level.push(root);
        while(true){
            leftMost = level.front();
            while(nodesConsumed < nodesInLevel){
                if(level.front()->left != NULL){
                    level.push(level.front()->left);
                    ++nodesInNextLevel;
                }
                if(level.front()->right != NULL){
                    level.push(level.front()->right);
                    ++nodesInNextLevel;
                }
                ++nodesConsumed;
                level.pop();
            }
            if(nodesInNextLevel == 0){
                return leftMost->val;
            }
            nodesInLevel = nodesInNextLevel;
            nodesInNextLevel = 0;
            nodesConsumed = 0;
        }
    }
};