class Solution {
public:
    vector<double> sums;
    vector<int> cnts;

    void func(TreeNode* root, int depth) {
        if (depth >= sums.size()) {
            sums.push_back(root->val);
            cnts.push_back(1);
        }
        else {
            sums[depth] += root->val;
            cnts[depth] += 1;
        }

        if (root->left != nullptr)  func(root->left, depth + 1);
        if (root->right != nullptr) func(root->right, depth + 1);
    }

    void makeAverage() {
        for (int i = 0; i < sums.size(); i++) {
            sums[i] /= cnts[i];
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        func(root, 0);
        makeAverage();
        return sums;
    }
};