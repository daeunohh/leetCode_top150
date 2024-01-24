class Solution {
public:
    int Nth = 0;
    int NthValue = -1;
    int k = 0;

    void func(TreeNode* root) {
        // L
        if (root->left != nullptr) {
            func(root->left);
        }

        // V
        Nth += 1;
        // cout << Nth << " " << k << " " << NthValue << endl;
        if (Nth == k) {
            NthValue = root->val;
            return;
        }

        // R
        if (root->right != nullptr) {
            func(root->right);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        func(root);
        return NthValue;
    }
};

