#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
struct nodeInfo {
    int depth;
    TreeNode* node;
};

class Solution {
public:
    queue<nodeInfo> q;

    void pushLeftNRight(nodeInfo* ni) {
        if (ni->node->left != nullptr) {
            q.push({ ni->depth + 1, ni->node->left });
        }
        if (ni->node->right != nullptr) {
            q.push({ ni->depth + 1, ni->node->right });
        }
        return;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        int deepest = 0;
        TreeNode* curr = root;
        q.push(nodeInfo({ 1, curr }));
        
        while (!q.empty()) {
            nodeInfo curNode = q.front(); q.pop();
            deepest = max(deepest, curNode.depth);
            pushLeftNRight(&curNode);
        }

        return deepest;
    }
};