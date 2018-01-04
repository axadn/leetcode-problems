/**Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> level = vector<TreeNode*>();
        vector<TreeNode*> nextLevel = vector<TreeNode*>();
        vector<TreeNode*> tmp;
        if(root != NULL){
            level.push_back(root->left);
            level.push_back(root->right);
        }

        while(!levelIsEmpty(level)){
            if(!levelIsSymmetric(level)){
                return false;
            }
            nextLevel.clear();
            for(int i = 0; i < level.size(); ++i){
                if(level[i]!= NULL){
                    nextLevel.push_back(level[i]->left);
                    nextLevel.push_back(level[i]->right);
                }
            }
            tmp = nextLevel;
            nextLevel = level;
            level = tmp;
        }
        return true;
    }
    inline bool levelIsEmpty(vector<TreeNode*>& level){
        if(level.empty()) return true;
        for(int i = 0; i < level.size(); ++i){
            if(level[i] != NULL) return false;
        }
        return true;
    }
    inline bool levelIsSymmetric(vector<TreeNode*>& level){
        TreeNode* left;
        TreeNode* right;
        for(int i = 0; i < level.size()/2; ++i){
            left = level[i];
            right = level[level.size() - 1 - i];
            if((right == NULL && left != NULL) ||
               (left == NULL && right != NULL)){
              return false;
            }
            else if(right != NULL && left != NULL){
                if(left-> val != right->val) return false;
            }
        }
        return true;
    }
};
