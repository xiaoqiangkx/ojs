/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> que, next_que;
        if (root != NULL) {
            que.push(root);
        }
        
        while (!que.empty()) {
            while (!que.empty()) {
                TreeLinkNode *tmp = que.front();
                que.pop();
                
                if (que.empty()) {
                    tmp->next = NULL;
                } else {
                    tmp->next = que.front();
                }
                
                if (tmp->left != NULL) {
                    next_que.push(tmp->left);
                }
                
                if (tmp->right != NULL) {
                    next_que.push(tmp->right);
                }
            }
            
            que.swap(next_que);
        }
    }
};