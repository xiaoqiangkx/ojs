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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        traverse(root, 1, result);
        return result;
    }
    
    void traverse(TreeNode *root, int level, vector<vector<int> > &result) {
        if (root == NULL) {
            return;
        }
        
        if (level > result.size()) {
            result.push_back(vector<int>());
        }
        
        result[level - 1].push_back(root->val);
        traverse(root->left, level + 1, result);
        traverse(root->right, level + 1, result);
    }
};


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
    vector<vector<int> > levelOrder(TreeNode *root) {
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
        
        return result;
    }
};