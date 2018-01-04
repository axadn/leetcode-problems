/**
Given preorder and inorder traversal of a tree, construct the binary tree.

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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        return buildTreeStep(preorder, 0, preorder.size(),inorder,0,inorder.size());
    }
    TreeNode* buildTreeStep(vector<int>& preorder, int preorderValIdx, int preorderEnd,vector<int>& inorder,int inorderStart,
                            int inorderEnd){
        int inorderValOffset = 0;
        while(inorder[inorderValOffset + inorderStart] != preorder[preorderValIdx]){
            ++inorderValOffset;
        }
        TreeNode* node = new TreeNode(preorder[preorderValIdx]);
        if(inorderValOffset != 0){
            node->left = buildTreeStep(preorder,preorderValIdx + 1, preorderValIdx + 1 + inorderValOffset,
                         inorder, inorderStart, inorderStart + inorderValOffset);
        }
        if(inorderStart +inorderValOffset + 1 != inorderEnd){
            node->right = buildTreeStep(preorder,preorderValIdx + 1 + inorderValOffset, preorderEnd,
                                       inorder, inorderStart + inorderValOffset + 1, inorderEnd);
        }
        return node;
    }
};
