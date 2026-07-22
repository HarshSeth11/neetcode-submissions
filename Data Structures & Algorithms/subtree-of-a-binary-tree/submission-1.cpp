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
    bool check(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;

        bool left = check(p->left, q->left);
        if(!left) return false;
        bool right = check(p->right, q->right);
        if(!right) return false;

        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(top->val == subRoot->val) {
                if(check(top,subRoot)) return true;
            }
            if(top->left) q.push(top->left);
            else if(top->right) q.push(top->right);
        }

        return false;
    }
};
