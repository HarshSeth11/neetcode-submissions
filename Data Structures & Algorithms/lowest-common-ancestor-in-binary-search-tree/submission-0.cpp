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
    TreeNode* solve(TreeNode* root, int sml, int grt) {
        if(root == NULL) {
            return NULL;
        }
        if(sml <= root->val && grt >= root->val) return root;

        TreeNode* left = solve(root->left, sml, grt);

        if(left) return left;

        TreeNode* right = solve(root->right, sml, grt);
        
        if(right) return right;


    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int smaller = min(p->val, q->val);
        int greater = max(p->val, q->val);

        return solve(root, smaller, greater);
    }
};
