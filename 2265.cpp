class Solution {
public:

    int ans = 0;

    pair<int, int> dfs(TreeNode* root) {

        // Base case
        if (root == NULL) {
            return {0, 0};
        }

        // Get sum and count from left subtree
        pair<int, int> left = dfs(root->left);

        // Get sum and count from right subtree
        pair<int, int> right = dfs(root->right);

        // Calculate current subtree sum
        int sum = left.first + right.first + root->val;

        // Calculate current subtree node count
        int count = left.second + right.second + 1;

        // Check average
        if (root->val == sum / count) {
            ans++;
        }

        // Return sum and count to parent
        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};