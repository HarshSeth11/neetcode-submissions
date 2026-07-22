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
    TreeNode* solve(vector<int>& preorder, int ileft, int iright, unordered_map<int, int>& mp) {
        if(ileft > iright) return NULL;
        TreeNode* root = new TreeNode(preorder[preidx++]);

        int split = mp[root->val];

        root->left = solve(preorder, ileft, split-1, mp);
        root->right = solve(preorder, split+1, iright, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return solve(preorder, 0, inorder.size()-1, mp);
    }
};
