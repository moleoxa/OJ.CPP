#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if (root) {
            stack<TreeNode*> s;
            s.push(root);
            auto pre = root;
            while (!s.empty()) {
                root = s.top();
                if (root->left && root->left != pre && root->right != pre) {
                    s.push(root->left);
                } else if (root->right && root->right != pre) {
                    s.push(root->right);
                } else {
                    s.pop();
                    v.push_back(root->val);
                    pre = root;
                }
            }
        }
        return v;
    }
};