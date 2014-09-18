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
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> tree_vec;
        stack<TreeNode*> s;
        
        TreeNode *p = root;
        
        while (!s.empty() || p != NULL) {
            if (p != NULL) {
                s.push(p);
                p = p->left;
            } else {
                TreeNode *tmp = s.top();
                s.pop();
                tree_vec.push_back(tmp);
                p = tmp->right;
            }
        }
        
        if (tree_vec.size() < 2) {
            return;
        }
        
        vector<TreeNode*> swap_vec;
        for (int i = 0; i < tree_vec.size() - 1; ++i) {
            if (tree_vec[i]->val > tree_vec[i+1]->val) {
                swap_vec.push_back(tree_vec[i]);
                break;
            }
        }
        
        for (int i = tree_vec.size() - 1; i > 0; --i) {
            if (tree_vec[i]->val < tree_vec[i-1]->val) {
                swap_vec.push_back(tree_vec[i]);
                break;
            }
        }
        
        if (swap_vec.size() >= 2) {
            int tmp = (swap_vec[0]->val);
            (swap_vec[0]->val) = (swap_vec[1]->val);
            (swap_vec[1]->val) = tmp;
        }
    }
};
