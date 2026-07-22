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

class Codec {
private:
    vector<string> split(string s, char delimiter) {
        vector<string> ans;
        stringstream ss(s);
        string token;

        while(getline(ss, token, delimiter)) {
            ans.push_back(token);
        }

        return ans;
    }

    void serializerHelper(TreeNode* root, vector<string>& res) {
        if(root == NULL) {
            res.push_back("N");
            return;
        }

        res.push_back(to_string(root->val));
        serializerHelper(root->left, res);
        serializerHelper(root->right, res);
    }

    string join(const vector<string> &v,const char &delim) {
        ostringstream s;
        for(const auto &i : v) {
            if(&i != &v[0])
                s << delim;
            s << i;
        }

        return s.str();
    }

    TreeNode* deserializeHelper(vector<string>& v, int& idx) {
        if(v[idx] == "N") {
            idx++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(v[idx]));
        idx++;
        root->left = deserializeHelper(v, idx);
        root->right = deserializeHelper(v, idx);

        return root;
    }
public:
    

    // 1,2,3,N,N,4,5

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        serializerHelper(root, res);
        return join(res, ',');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v = split(data, ',');
        int idx = 0;
        return deserializeHelper(v, idx);
    }
};
