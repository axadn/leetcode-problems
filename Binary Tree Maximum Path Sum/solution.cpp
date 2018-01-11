/**
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int maxPathSum(TreeNode* root) {
        int maxPathSum;
        int maxDepthSum;
        getMaxes(root, maxPathSum, maxDepthSum);
        return maxPathSum;
    }
    void getMaxes(TreeNode* node, int& maxPathSum, int& maxDepthSum){
        vector<int> candidates;
        vector<int> depthCandidates;
        int leftmaxPathSum, leftmaxDepthSum;
        int rightmaxPathSum, rightmaxDepthSum;
        if(node->left != NULL){
            getMaxes(node->left, leftmaxPathSum, leftmaxDepthSum);
            depthCandidates.push_back(leftmaxDepthSum);
            candidates.push_back(leftmaxPathSum);
        }
        if(node->right != NULL){
            getMaxes(node->right, rightmaxPathSum, rightmaxDepthSum);
            candidates.push_back(rightmaxPathSum);
            depthCandidates.push_back(rightmaxDepthSum);
        }
        if(node->right != NULL && node->left != NULL){
            candidates.push_back(leftmaxDepthSum + rightmaxDepthSum + node->val);
        }
        maxDepthSum = node->val;
        for(int i = 0; i < depthCandidates.size(); ++i){
            maxDepthSum = std::max(maxDepthSum, depthCandidates[i] + node->val);
        }
        
        candidates.push_back(maxDepthSum);
        maxPathSum = node->val;
        for(int i = 0; i < candidates.size(); ++i){
            maxPathSum = std::max(maxPathSum, candidates[i]);
        }
    }
};
