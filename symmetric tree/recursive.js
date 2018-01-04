/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
const isSymmetric = function(root) {
    if(root == null ) return true;
    return symmetricStep(root.left, root.right);
};

const symmetricStep = function(left, right){
    if(left == null || right == null) return (left == right);
    return (right.val == left.val &&
            symmetricStep(left.right,right.left) &&
            symmetricStep(left.left, right.right));
}
