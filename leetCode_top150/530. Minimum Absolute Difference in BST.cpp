class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minGap = 1000000;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto curV = q.front();  q.pop();

            if (curV->left != nullptr) {
                minGap = min(minGap, curV->val - curV->left->val);
                q.push(curV->left);
            }
            if (curV->right != nullptr) {
                minGap = min(minGap, curV->right->val - curV->val);
                q.push(curV->right);
            }

            if (minGap == 0) return 0;
        }
        return minGap;
    }
};