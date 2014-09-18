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
    int sumNumbers(TreeNode *root) {
        return calculateSum(root, 0);
    }
    
    int calculateSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return 0;
        }
        
        sum = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum;
        }
        
        return calculateSum(root->left, sum) +
               calculateSum(root->right, sum);
    }
};
