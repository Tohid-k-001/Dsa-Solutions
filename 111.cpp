class Solution {
public:
    int minDepth(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            return 1;
        }

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (root->left == NULL || root->right == NULL) {
            return leftDepth + rightDepth + 1;
        }

        return min(leftDepth, rightDepth) + 1;
    }
};