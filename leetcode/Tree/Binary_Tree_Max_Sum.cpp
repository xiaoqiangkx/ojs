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
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        int csum = 0;
        calculateSum(root, csum, maxSum);
        return maxSum;
    }
    
    void calculateSum(TreeNode *root, int &csum, int &maxSum) {
        if (root == NULL) {
            csum = 0;
            return;
        }
        
        int lsum = 0;
        int rsum = 0;
        calculateSum(root->left, lsum, maxSum);
        calculateSum(root->right, rsum, maxSum);
        
        csum = max(root->val, max(root->val + lsum, root->val + rsum));
        maxSum = max(maxSum, max(csum, root->val + lsum + rsum));
    }
};
