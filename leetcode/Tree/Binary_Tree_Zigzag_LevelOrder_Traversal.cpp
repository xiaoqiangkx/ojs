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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        list<int> tmp_list;
        
        queue<TreeNode*> que, next_que;
        
        if (root != NULL) {
            que.push(root);
        }
        
        bool leftToRight = true;
        while (!que.empty() || !next_que.empty()) {
            if (que.empty()) {
                que.swap(next_que);
                result.push_back(vector<int>(tmp_list.begin(), tmp_list.end()));
                tmp_list.clear();
                leftToRight = !leftToRight;
            }
            
            TreeNode *tmp = que.front();
            que.pop();
            
            if (leftToRight) {
                tmp_list.push_back(tmp->val);
            } else {
                tmp_list.push_front(tmp->val);
            }
            
            if (tmp->left != NULL) {
                next_que.push(tmp->left);
            }
            
            if (tmp->right != NULL) {
                next_que.push(tmp->right);
            }
        }
        
        if (!tmp_list.empty()) {
            result.push_back(vector<int>(tmp_list.begin(), tmp_list.end()));
        }
        
        return result;
    }
};
