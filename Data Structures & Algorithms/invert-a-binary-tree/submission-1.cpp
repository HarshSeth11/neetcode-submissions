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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->left && root->right) {
            TreeNode* temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        else if(root->right) {
            root->left = root->right;
            root->right = NULL;
        }
        else if(root->left) {
            root->right = root->left;
            root->left = NULL;
        }
        else return root;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
