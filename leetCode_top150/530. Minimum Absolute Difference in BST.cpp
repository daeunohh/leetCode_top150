class Solution {
private:
    static const int maxGap = 100001;

    struct p {
        TreeNode* node;
        int minGap = maxGap;
    };

public:
    int getMinimumDifference(TreeNode* root) {
        int MinGap = maxGap;
        queue<p> q;
        q.push({ root, maxGap });

        while (!q.empty()) {
            auto curP = q.front(); q.pop();

            if (curP.node->left != nullptr) {
                int leftGap = curP.node->val - curP.node->left->val;
                q.push({ curP.node->left, min(leftGap, leftGap + curP.minGap) });
            }
            if (curP.node->right != nullptr) {
                int rightGap = curP.node->right->val - curP.node->val;
                q.push({ curP.node->right, min(rightGap, rightGap + curP.minGap) });
            }

            if (curP.node->left == nullptr && curP.node->right == nullptr) {
                MinGap = min(MinGap, abs(curP.minGap));
            }
        }

        return MinGap;
    }
};