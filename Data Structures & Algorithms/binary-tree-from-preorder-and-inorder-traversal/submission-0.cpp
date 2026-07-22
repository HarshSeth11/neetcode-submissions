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
    int preidx = 0;
    TreeNode* solve(vector<int> preorder, vector<int> inorder) {
        if(inorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[preidx++]);
        int split = 0;
        for(int i=0; i<inorder.size(); i++) {
            if(inorder[i] == root->val) split = i;
        }

        cout<<split<<endl;

        vector<int> left(inorder.begin(), inorder.begin()+split);
        vector<int> right(inorder.begin()+split+1, inorder.end());

        root->left = solve(preorder, left);
        root->right = solve(preorder, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder);
    }
};
