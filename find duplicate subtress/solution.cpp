/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class NodeLookup{
    TreeNode * node;
    unordered_set<int, NodeLookup> lookup;
}
struct stackFrame{
    bool leftvisited;
    bool leftSatisfied;
    bool rightVisited;
    bool rightSatisfie;
}
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> solution;
        solution.push_back(root->left);
       
    }
};
/**

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
      
      basic idea: 
        nested lookup trees with the leaves of input tree being roots of lookup tree
        it will be built up as we do a post order traversal
        
        example : {
                    4:{
                        2:{
                            3,
                            1
                        }
                    },
                    3: {1}
                  }
      This will allow us O(n) time and space complexity
      
      pseudo code
      
      newPath = false
       if(node.left == null && node.right == null)
            lookup = leafLookup
            newPath = false
            if(leafLookup[node]) solutionSet.push(node)
            pop top
            if(lookup[top])
                lookup =lookup[top]
            else 
                newPath = true
                newLookup(top)
                (lookup.push(newLookup))
                lookup = newLookup
            next
       else if !newPath && lookup[top] && stackFrame.leftSatisfied && stackFrame.rightSatisfied
                solution.push(top)
       else
                 newLookup(top)
                (lookup.push(newLookup))
                lookup = newLookup
                        newPath = true
                         newLookup(top)
                        (lookup.push(newLookup))
                        lookup = newLookup
                            
      
**/
