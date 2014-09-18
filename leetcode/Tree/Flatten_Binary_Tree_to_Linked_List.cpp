/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    void flatten(TreeNode *root) {
        TreeNode dummy(-1);
        TreeNode *tail = &dummy;
        flattenTree(root, tail);
        root = dummy.right;
    }
    
    void flattenTree(TreeNode *root, TreeNode *(&tail)) {
        if (root == NULL) {
            return;
        }
        
        TreeNode *tmp_left = root->left;
        TreeNode *tmp_right = root->right;
        
        tail->right = root;
        tail->left = NULL;
        tail = tail->right;
        flattenTree(tmp_left, tail);
        flattenTree(tmp_right, tail);

    }
};


class Solution2 {
public:
    void flatten(TreeNode *root) {
        TreeNode dummy(-1);
        TreeNode *tail = &dummy;
        stack<TreeNode*> s;
        
        if (root != NULL) {
            s.push(root);
        }
        
        while (!s.empty()) {
            TreeNode *tmp = s.top();
            s.pop();
            
            tail->right = tmp;
            tail->left = NULL;
            tail = tail->right;
            
            if (tmp->right != NULL) {
                s.push(tmp->right);
            }
            
            if (tmp->left != NULL) {
                s.push(tmp->left);
            }
        }
        
        root = dummy.right;
    }
};