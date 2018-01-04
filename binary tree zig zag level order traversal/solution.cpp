/**
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levels = vector<vector<int>>();
        vector<int> level = vector<int>();
        deque<TreeNode*> q = deque<TreeNode*>();
        q.push_back(root);

        int levelCount = 1;
        int nextLevelCount = 0;
        bool zag = true;
        TreeNode* element;
        while(!q.empty()){
            if(levelCount == 0){
                levels.push_back(level);
                level = vector<int>();
                levelCount = nextLevelCount;
                nextLevelCount = 0;
                zag = !zag;
            }
            element = zag ? q.back() : q.front();
            if(element != NULL){
                nextLevelCount += 2;
                level.push_back(element->val);
                if(zag){
                  q.push_front(element->left);
                  q.push_front(element->right);
                }
                else{
                  q.push_back(element->right);
                  q.push_back(element->left);
                }
            }
              if(zag){
                 q.pop_back();
              }
            else{
                q.pop_front();
            }
            --levelCount;
        }
        return levels;
    }
};
