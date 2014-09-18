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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return sortedArrayToBST(num, 0, num.size() - 1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num, int st, int ed) {
        if (st > ed) {
            return NULL;
        }
        
        int mid = st + (ed - st) / 2;
        TreeNode *mid_node = new TreeNode(num[mid]);
        mid_node->left = sortedArrayToBST(num, st, mid - 1);
        mid_node->right = sortedArrayToBST(num, mid + 1, ed);
        return mid_node;
    }
};
