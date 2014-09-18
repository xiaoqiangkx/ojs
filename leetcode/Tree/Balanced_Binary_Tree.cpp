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
    bool isBalanced(TreeNode *root) {
        return BalancedHeight(root) >= 0;
    }
    
    int BalancedHeight(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = BalancedHeight(root->left);
        int right = BalancedHeight(root->right);
        
        if (left < 0 || right < 0 || abs(left - right) > 1) {
            return -1;
        }
        
        return max(left, right) + 1;
    }
};