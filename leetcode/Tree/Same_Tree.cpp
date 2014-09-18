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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        
        while (!s.empty()) {
            p = s.top();
            s.pop();
            q = s.top();
            s.pop();
            
            if (!p && !q) {
                continue;
            } else if (!p || !q) {
                return false;
            } else if (p->val != q->val) {
                return false;
            }
            
            s.push(p->left);
            s.push(q->left);
            s.push(p->right);
            s.push(q->right);
        }

        return true;
    }
};