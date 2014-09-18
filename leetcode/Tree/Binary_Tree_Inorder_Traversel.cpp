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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> s;
        
        TreeNode *p = root;
        
        while (!s.empty() || p != NULL) {
            if (p != NULL) {
                s.push(p);
                p = p->left;
            } else {
                TreeNode *tmp = s.top();
                s.pop();
                result.push_back(tmp->val);
                p = tmp->right;
            }
        }
        
        return result;
    }
};