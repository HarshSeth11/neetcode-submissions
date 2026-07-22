/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int solve(TreeNode* root, int maxi) {
        if(root == NULL) return 0;

        int left = solve(root->left, max(maxi, root->val));
        int right = solve(root->right, max(maxi, root->val));

        if(root->val >= maxi) return left+right+1;
        
        return left+right;
    }
    int goodNodes(TreeNode* root) {
        return solve(root, INT_MIN);
    }
};
