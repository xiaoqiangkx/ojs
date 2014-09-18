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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode *root, int left, int right) {
        if (root == NULL) {
            return true;
        }
        
        if (root->val > left && root->val < right) {
            return isValidBST(root->left, left, root->val) &&
                   isValidBST(root->right, root->val, right);
        }
        
        return false;
    }
};
