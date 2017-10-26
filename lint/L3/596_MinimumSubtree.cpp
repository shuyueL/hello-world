/*Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.*/

//mine
class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    TreeNode * findSubtree(TreeNode * root) {
        // write your code here
        helper(root);
        return node;
    }
    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left = helper(root->left);
        int right = helper(root->right);
        int current = left + right + root->val;
        if (node == NULL ||current < minsum) {
            node = root;
            minsum = current;
        }
        return current;
    }
private:
    TreeNode* node = NULL;
    int minsum;
};

//jiuzhang
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return the minimun weight node
     */
    TreeNode* findSubtree(TreeNode* root) {
        // Write your code here
        helper(root);
        return result;
    }

    int helper(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int left_weight = helper(root->left);
        int right_weight = helper(root->right);

        if (left_weight + right_weight + root->val <= minumun_weight) {
            minumun_weight = left_weight + right_weight + root->val;
            result = root;
        }
        return left_weight + right_weight + root->val;
    }

private:
    TreeNode* result = nullptr;
    int minumun_weight = INT_MAX;
};
