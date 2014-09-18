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
    bool isSymmetric(TreeNode *root) {
        stack<TreeNode*> s;
        if (root == NULL) {
            return true;
        } else {
            s.push(root->left);
            s.push(root->right);
        }
        
        while (!s.empty()) {
            TreeNode *p = s.top();
            s.pop();
            TreeNode *q = s.top();
            s.pop();
            
            if (!p && !q) {
                continue;
            } else if (!p || !q) {
                return false;
            } else if (p->val != q->val) {
                return false;
            } else {
                s.push(p->left);
                s.push(q->right);
                s.push(p->right);
                s.push(q->left);
            }
        }
        
        return true;
    }
};