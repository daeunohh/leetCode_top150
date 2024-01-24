
class Solution {
private:
    static const int maxGap = 100001;
    int MinGap = maxGap;

public:
    TreeNode* getNearestNode_Left(TreeNode* root) {
        root = root->left;

        while (root->right != nullptr) {
            root = root->right;
        }

        return root;
    }

    TreeNode* getNearestNode_Right(TreeNode* root) {
        root = root->right;

        while (root->left != nullptr) {
            root = root->left;
        }

        return root;
    }

    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> q;
        q.push({ root });

        while (!q.empty()) {
            auto cur = q.front(); q.pop();

            if (cur->left != nullptr) {
                auto minGapL = cur->val - getNearestNode_Left(cur)->val;
                MinGap = min(MinGap, minGapL);
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                auto minGapR = getNearestNode_Right(cur)->val - cur->val;
                MinGap = min(MinGap, minGapR);
                q.push(cur->right);
            }

        }

        return MinGap;
    }
};