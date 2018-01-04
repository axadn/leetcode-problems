/**Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
/**
my solution using a queue **/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels = vector<vector<int>>();
        vector<int> level = vector<int>();
        queue<TreeNode*> q = queue<TreeNode*>();
        q.push(root);

        int levelCount = 1;
        int nextLevelCount = 0;
        while(!q.empty()){
            if(levelCount == 0){
                levels.push_back(level);
                level = vector<int>();
                levelCount = nextLevelCount;
                nextLevelCount = 0;
            }
            if(q.front() != NULL){
                nextLevelCount += 2;
                level.push_back(q.front()->val);
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
            --levelCount;
        }
        return levels;
    }
};
