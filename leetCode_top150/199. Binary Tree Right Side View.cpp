class Solution {
public:
    vector<int> vals; int sz = 0;

    void func(TreeNode* root, int depth) {
        if (depth >= sz) {
            vals.push_back(root->val); sz++;
        }

        if (root->right != nullptr) func(root->right, depth + 1);
        if (root->left != nullptr)  func(root->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        func(root, 0);
        return vals;
    }
};