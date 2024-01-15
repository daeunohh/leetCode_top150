class Solution {
public:
    vector<int> maxRight;
    vector<int> vals;

    void func(TreeNode* root, int depth, int rightness) {
        if (depth >= maxRight.size()) {
            maxRight.push_back(rightness);
            vals.push_back(root->val);
        }

        if (root->right != nullptr) func(root->right, depth + 1, rightness + 1);
        if (root->left != nullptr)  func(root->left, depth + 1, rightness - 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        func(root, 0, 0);
        return vals;
    }
};