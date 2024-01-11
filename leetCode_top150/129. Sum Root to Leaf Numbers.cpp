struct e {
    TreeNode* node;
    int sum;
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;

        int totalSum = 0;
        queue<e> q; q.push(e({ root, 0 }));

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            cur.sum = cur.sum * 10 + cur.node->val;

            if (cur.node->left == nullptr && cur.node->right == nullptr) {
                totalSum += cur.sum;
                continue;
            }

            if (cur.node->left != nullptr)  q.push(e({ cur.node->left, cur.sum }));
            if (cur.node->right != nullptr) q.push(e({ cur.node->right, cur.sum }));
        }

        return totalSum;
    }
};