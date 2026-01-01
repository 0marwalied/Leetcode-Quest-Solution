class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root)return NULL;
        TreeNode* left = searchBST(root->left, val);
        TreeNode* right = searchBST(root->right, val);
        if (root->val == val)return root;
        TreeNode* ret = left ? left : right ? right : NULL;
        return ret;
    }
};