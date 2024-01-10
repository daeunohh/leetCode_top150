class Solution {
public:
    bool func(TreeNode* node, int curSum, int targetSum) {
        curSum += node->val;

        if (node->left == nullptr && node->right == nullptr) return (curSum == targetSum);

        if (node->left != nullptr) {
            if (func(node->left, curSum, targetSum)) return true;
        }
        if (node->right != nullptr) {
            if (func(node->right, curSum, targetSum)) return true;
        }

        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return func(root, 0, targetSum);
    }
};