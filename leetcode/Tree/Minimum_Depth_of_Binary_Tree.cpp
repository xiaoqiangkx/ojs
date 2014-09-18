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
    int minDepth(TreeNode *root) {
        if (root == NULL) { return 0; }
        queue<TreeNode*> que, next_que;
        
        que.push(root);
        int depth = 1;
        
        while (!que.empty()) {
            while (!que.empty()) {
                TreeNode *tmp = que.front();
                que.pop();
                
                if (tmp->left == NULL && tmp->right == NULL) {
                    return depth;
                }
                
                if (tmp->left != NULL) {
                    next_que.push(tmp->left);
                }
                
                if (tmp->right != NULL) {
                    next_que.push(tmp->right);
                }
            }
            
            que.swap(next_que);
            depth++;
        }
        
        return depth - 1;
    }
};


class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL) { return 0;}
        if (root->left == NULL && root->right == NULL) {
            return 1;
        } else if (root->left == NULL) {
            return minDepth(root->right) + 1;
        } else if (root->right == NULL) {
            return minDepth(root->left) + 1;
        } else {
            return min (minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
};
