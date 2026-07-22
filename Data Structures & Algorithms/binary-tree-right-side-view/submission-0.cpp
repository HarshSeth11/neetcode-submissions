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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        list<TreeNode*> lst;
        lst.push_back(root);

        while(!lst.empty()) {
            int size = lst.size();

            ans.push_back(lst.back()->val);
            while(size--) {
                TreeNode* front = lst.front();
                lst.pop_front();

                if(front->left) lst.push_back(front->left);
                if(front->right) lst.push_back(front->right);
            }
        }

        return ans;
    }
};
