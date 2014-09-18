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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> tmp;
        fillPath(root, sum, tmp, result);
        return result;
    }
    
    void fillPath(TreeNode *root, int sum, vector<int> &tmp, vector<vector<int> > &result) {
        if (root == NULL) {
            return;
        }
        
        tmp.push_back(root->val);
        sum -= root->val;
        
        if (root->left == NULL && root->right == NULL) {
            if (sum == 0) {
                result.push_back(tmp);
            }
            
            tmp.pop_back();
            return;
        }
        
        fillPath(root->left, sum, tmp, result);
        fillPath(root->right, sum, tmp, result);
        tmp.pop_back();
    }
};
