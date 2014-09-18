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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        queue<TreeNode*> que;
        queue<TreeNode*> next_que;
        
        vector<int> tmp_vec;
        
        if (root != NULL) {
            que.push(root);
        }
        
        while (!que.empty() || !next_que.empty()) {
            
            if (que.empty()) {
                que.swap(next_que);
                result.push_back(tmp_vec);
                tmp_vec.clear();
            }
            TreeNode *tmp = que.front();
            que.pop();
            
            tmp_vec.push_back(tmp->val);
            if (tmp->left != NULL) {
                next_que.push(tmp->left);
            }
            
            if (tmp->right != NULL) {
                next_que.push(tmp->right);
            }
        }
        
        if (!tmp_vec.empty()) {
            result.push_back(tmp_vec);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
