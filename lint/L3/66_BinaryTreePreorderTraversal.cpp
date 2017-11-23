/*Given a binary tree, return the preorder traversal of its nodes' values.*/


class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
    vector<int> preorderTraversal(TreeNode * root) {
        // write your code here
        preorder.clear();
        traversal(root);
        return preorder;
    }
    
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        preorder.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
    
private:
    vector<int> preorder;
};
