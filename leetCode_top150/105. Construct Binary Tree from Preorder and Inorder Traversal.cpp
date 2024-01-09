class Solution {
public:
    TreeNode* getLVR(vector<int>::iterator pre, vector<int>::iterator in, int termLength) {
        int V = *pre;
        TreeNode* currV = new TreeNode(V);

        int dist = 0; auto tmp = in;
        while (*tmp != V) {
            ++tmp; ++dist;
        }

        if (dist != 0) currV->left = getLVR(pre + 1, in, dist);
        if (dist < termLength - 1) currV->right = getLVR(pre + dist + 1, in + dist + 1, termLength - 1 - dist);

        return currV;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return getLVR(preorder.begin(), inorder.begin(), preorder.size());
    }
};