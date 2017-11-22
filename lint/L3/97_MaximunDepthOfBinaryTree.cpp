/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.*/

//mine
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
        if (root == NULL) return 0;
        return helper(root);
    }
    
    int helper(TreeNode* root){
        if (root == NULL) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        return max(left,right)+1;
    }
};

//jiuzhang
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
};

