class Solution {
private:
    static const int maxGap = 100001;
    int MinGap = maxGap;

    struct p {
        TreeNode* node;
        int minGap = maxGap;
    };

public:
    void func(TreeNode* node, int minGap) {
        MinGap = min(MinGap, abs(minGap));

        if (node->left != nullptr) {
            int leftGap = node->left->val - node->val;
            func(node->left, leftGap);
            func(node->left, leftGap + minGap);
        }
        if (node->right != nullptr) {
            int rightGap = node->right->val - node->val;
            func(node->right, rightGap);
            func(node->right, rightGap + minGap);
        }
    }


    int getMinimumDifference(TreeNode* root) {
        func(root, maxGap);

        /*queue<p> q;
        q.push({ root, maxGap });

        while (!q.empty()) {
            auto curP = q.front(); q.pop();
            MinGap = min(MinGap, abs(curP.minGap));

            if (curP.node->left != nullptr) {
                int leftGap = curP.node->left->val - curP.node->val;
                q.push({ curP.node->left, leftGap });
                q.push({ curP.node->left, leftGap + curP.minGap });
            }
            if (curP.node->right != nullptr) {
                int rightGap = curP.node->right->val - curP.node->val;
                q.push({ curP.node->right, rightGap });
                q.push({ curP.node->right, rightGap + curP.minGap });
            }
        }*/

        return MinGap;
    }
};