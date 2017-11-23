/*Given a binary tree, return the inorder traversal of its nodes' values.*/

class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */

    
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        inorder.clear();
        traversal(root);
        return inorder;
    }

    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);
        inorder.push_back(root->val);
        traversal(root->right);
    }


private: 
    vector<int> inorder;

};
