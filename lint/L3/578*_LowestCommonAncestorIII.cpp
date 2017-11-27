/*Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.*/

//jiuzhang
class ResultType {
public:
    bool a_exist, b_exist;
    TreeNode* node;
    ResultType(bool a, bool b, TreeNode* n) {
        a_exist = a;
        b_exist = b;
        node =  n;
    }
};

class Solution {
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        // write your code here
        ResultType rt = helper(root, A, B);
        if (rt.a_exist && rt.b_exist)
            return rt.node;
        else
            return NULL;
    }
    
    ResultType helper(TreeNode* root, TreeNode* A, TreeNode* B) {
        if (root == NULL)
            return ResultType(false, false, NULL);
            
        ResultType left_rt = helper(root->left, A, B);
        ResultType right_rt = helper(root->right, A,B);
        
        bool a_exist = left_rt.a_exist || right_rt.a_exist || root == A;
        bool b_exist = left_rt.b_exist || right_rt.b_exist || root == B;
        
        if (root == A || root == B)
            return ResultType(a_exist, b_exist, root);
            
        if (left_rt.node != NULL && right_rt.node != NULL)
            return ResultType(a_exist, b_exist, root);
        if (left_rt.node != NULL)
            return ResultType(a_exist, b_exist,left_rt.node);
        if (right_rt.node != NULL)
            return ResultType(a_exist, b_exist, right_rt.node);
            
        return ResultType(a_exist, b_exist, NULL);
    }
};
