/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int n = count(head);
        return sortedListToBST(head, n);
    }
    
    TreeNode *sortedListToBST(ListNode *(&head), int n) {
        if (n == 0) { return NULL; }
        if (n == 1) {
            TreeNode *tmp = new TreeNode(head->val);
            head = head->next;
            return tmp;
        }
        
        TreeNode *left = sortedListToBST(head, n / 2);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = sortedListToBST(head, n - n / 2 - 1);
        return root;
    }
    
    int count (ListNode *head) {
        int cnt = 0;
        while (head) {
            ++cnt;
            head = head->next;
        }
        
        return cnt;
    }
};