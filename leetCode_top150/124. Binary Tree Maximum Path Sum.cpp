class Solution {
public:
#define MAX(a, b) (((a) > (b))? (a) : (b))

    int returnSum = 0; bool isFirst = true;

    int getMaxSum(TreeNode* V) {
        if (V->left == nullptr && V->right == nullptr) {
            if (isFirst) {
                returnSum = V->val; isFirst = false;
            }
            else
                returnSum = MAX(returnSum, V->val);
            return V->val;
        }

        int sumArray[3] = { -1001,-1001,-1001, }; int sumResult[3] = { -1001,-1001,-1001, };

        if (V->left != nullptr) sumArray[0] = getMaxSum(V->left);
        sumArray[1] = V->val;
        if (V->right != nullptr) sumArray[2] = getMaxSum(V->right);

        int maxSum = sumArray[0];
        sumResult[0] = sumArray[0];

        for (int i = 1; i < 3; i++) {
            if (sumArray[i] < sumArray[i] + sumResult[i - 1]) {
                sumResult[i] = sumArray[i] + sumResult[i - 1];
            }
            else sumResult[i] = sumArray[i];

            if (sumResult[i] > maxSum) maxSum = sumResult[i];
        }

        if (isFirst) {
            returnSum = maxSum; isFirst = false;
        }
        else
            returnSum = MAX(returnSum, maxSum);

        return sumArray[1] + MAX(0, (MAX(sumArray[0], sumArray[2])));
    }

    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        getMaxSum(root);
        return returnSum;
    }
};