#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* build(int* preorder, int preroot, int* inorder, int l, int r, int* hash) {
    if (l > r) {
        return NULL;
    }
    struct  TreeNode* root = (struct  TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preroot];
    int inroot = hash[root->val + 3000];
    root->left = build(preorder, preroot + 1, inorder, l, inroot - 1, hash);
    root->right = build(preorder, preroot + inroot - l + 1, inorder, inroot + 1, r, hash);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int hash[6001];
    for (int i = 0; i < inorderSize; i++) {
        hash[inorder[i] + 3000] = i;
    }
    return build(preorder, 0, inorder, 0, inorderSize - 1, hash);
}