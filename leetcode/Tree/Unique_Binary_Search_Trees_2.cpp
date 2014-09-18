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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return generateTrees(1, 0);
        }
        
        return generateTrees(1, n);
    }
    
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> subTree;
        if (start > end) {
            subTree.push_back(NULL);
            return subTree;
        }
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTree = generateTrees(start, i - 1);
            vector<TreeNode*> rightTree = generateTrees(i + 1, end);
            
            for (int j = 0; j < leftTree.size(); ++j) {
                for (int k = 0; k < rightTree.size(); ++k) {
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = leftTree[j];
                    tmp->right = rightTree[k];
                    subTree.push_back(tmp);
                }
            }
        }
        
        return subTree;
    }
};
