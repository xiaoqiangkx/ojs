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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder.begin(), inorder.end(),
                         postorder.begin(), postorder.end());
    }
    
    TreeNode *buildTree(iter_type in_first, iter_type in_end, iter_type post_first, iter_type post_end) {
        if (in_first == in_end) {
            return NULL;
        }
        
        if (post_first == post_end) {
            return NULL;
        }
        
        iter_type in_target = find(in_first, in_end, *(post_end - 1));
        int dis = distance(in_first, in_target);
        
        TreeNode *root = new TreeNode(*(post_end - 1));
        root->left = buildTree(in_first, in_target, post_first, post_first + dis);
        root->right = buildTree(in_target + 1, in_end, post_first + dis, post_end - 1);
        return root;
    }
};
