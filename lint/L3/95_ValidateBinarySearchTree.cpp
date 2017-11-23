/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
A single node tree is a BST*/


//jiuzhang-divide&conquer
class ResultType {
public:
    bool isBST;
    TreeNode *maxNode, *minNode;
    ResultType() {
        this->isBST = true;
        this->maxNode = NULL;
        this->minNode = NULL;
    }
};

class Solution {
public:
    /*
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
     
    bool isValidBST(TreeNode * root) {
        // write your code here
        if (root == NULL) return true;
        return helper(root).isBST;
        
    }
    
    ResultType helper(TreeNode* root) {
        ResultType result;
        if (root == NULL) {
            return result;
        }
        
        ResultType left = helper(root->left);
        ResultType right = helper(root->right);
        
        if(!left.isBST || !right.isBST){
            result.isBST = false;
            return result;
        }
        if (left.maxNode!= NULL && left.maxNode->val>= root->val) {
            result.isBST = false;
            return result;
        }
        if (right.minNode != NULL && right.minNode->val <= root->val) {
            result.isBST = false;
            return result;
        }
        result.isBST = true;
        result.minNode = left.minNode == NULL ? root:left.minNode;
        result.maxNode = right.maxNode == NULL ? root: right.maxNode;
        return result;
    }
    
};

//jiuzhang-ver2.
class Solution {
private:
    TreeNode *lastNode = NULL;
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        if (!isValidBST(root->left)) {
            return false;
        }
        if (lastNode != NULL && lastNode->val >= root->val) {
            return false;
        }
        lastNode = root;
        return isValidBST(root->right);
    }
};
