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
    vector<int> ans;
    void preorder(TreeNode* root, int k) {
        if(root == NULL) return;

        preorder(root->left, k);
        ans.push_back(root->val);
        preorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        preorder(root, k);
        return ans[k-1];
    }
};
