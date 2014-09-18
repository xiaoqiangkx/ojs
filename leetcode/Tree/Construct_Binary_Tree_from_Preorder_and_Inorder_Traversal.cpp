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
private:
    typedef vector<int>::iterator iter_type;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder.begin(), preorder.end(),
                         inorder.begin(), inorder.end());
    }
    
    TreeNode *buildTree(iter_type pre_first, iter_type pre_end, iter_type in_first, iter_type in_end) {
        if (pre_first == pre_end) {
            return NULL;
        }
        
        if (in_first == in_end) {
            return NULL;
        }
        
        iter_type in_target = find(in_first, in_end, *pre_first);
        int dis = distance(in_first, in_target);
        
        TreeNode *root = new TreeNode(*pre_first);
        root->left = buildTree(pre_first + 1, pre_first + dis + 1, in_first, in_target);
        root->right = buildTree(pre_first + dis + 1, pre_end, in_target + 1, in_end);
        return root;
    }
};
