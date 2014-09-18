/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        
        if (root != NULL) {
            s.push(root);
        }
        
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            s.pop();
            result.push_back(tmp->val);
            
            if (tmp->right != NULL) {
                s.push(tmp->right);
            }
            
            if (tmp->left != NULL) {
                s.push(tmp->left);
            }
        }
        
        return result;
    }
};