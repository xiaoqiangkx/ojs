#include <iostream>
#include <climits>
using namespace std; 

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    int maxPathSum(TreeNode *root) {
       int csum = INT_MIN;
       int maxSum = INT_MIN;
       calculateSum(root, csum, maxSum);
       return maxSum;
    }
    
    void calculateSum(TreeNode *root, int &csum, int &maxSum) {
        if (root == NULL) {
            csum = 0;
            return;
        }
        
        int lcsum, rcsum;
        calculateSum(root->left, lcsum, maxSum);
        calculateSum(root->right, rcsum, maxSum);
        csum = max(csum, max(root->val + lcsum, root->val + rcsum));
        maxSum = max(maxSum, max(csum, lcsum + rcsum + root->val));
    }
};

int main() {
	TreeNode node1(1);
	TreeNode node2(2);
	node1.right = &node2;
	Solution s;
	cout << s.maxPathSum(&node1) << endl;
	return 0;
}
