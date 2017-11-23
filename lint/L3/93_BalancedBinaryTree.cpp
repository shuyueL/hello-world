/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.*/


class Solution {
public:
    /*
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        // write your code here
        return getDepth(root)!=-1;
        
    }
    
    int getDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        if (left == -1||right == -1 ||abs(left-right) >1){
            return -1;
        }
        return max(left,right)+1;
    }
};
