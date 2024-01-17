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
            MinGap = min(MinGap, abs(curP.minGap));

            if (curP.node->left != nullptr) {
                int leftGap = curP.node->left->val - curP.node->val;
                q.push({ curP.node->left, leftGap });
                q.push({ curP.node->left, leftGap + curP.minGap });

                /*if(abs(leftGap) < abs(leftGap + curP.minGap))
                    q.push({ curP.node->left, leftGap });
                else
                    q.push({ curP.node->left, leftGap + curP.minGap });*/
            }
            if (curP.node->right != nullptr) {
                int rightGap = curP.node->right->val - curP.node->val;
                q.push({ curP.node->right, rightGap });
                q.push({ curP.node->right, rightGap + curP.minGap });

                /*if (abs(rightGap) < abs(rightGap + curP.minGap))
                    q.push({ curP.node->right, rightGap });
                else
                    q.push({ curP.node->right, rightGap + curP.minGap });*/
            }
        }

        return MinGap;
    }
};