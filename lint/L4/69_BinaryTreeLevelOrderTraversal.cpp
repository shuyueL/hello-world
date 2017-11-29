/*Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).*/


class Solution {
public:
    /*
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if (root == NULL) return result;
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        
        while (!myQueue.empty()) {
            int size = myQueue.size();
            vector<int> level;
            
            for (int i = 0; i<size; i++) {
                TreeNode* head = myQueue.front(); myQueue.pop();
                level.push_back(head->val);
                if (head->left!=NULL) {
                    myQueue.push(head->left);
                }
                if (head->right!=NULL) {
                    myQueue.push(head->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
