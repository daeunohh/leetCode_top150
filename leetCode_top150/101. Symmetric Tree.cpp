#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> LeftQ{ {root->left} };
        queue<TreeNode*> RightQ{ {root->right} };

        while (!LeftQ.empty() || !RightQ.empty()) {
            auto Lfront = LeftQ.front();
            auto Rfront = RightQ.front();

            if (Lfront == nullptr && Rfront == nullptr) {
                LeftQ.pop(); RightQ.pop();
            }
            else if (Lfront != nullptr && Rfront != nullptr) {
                if (Lfront->val != Rfront->val)
                    return false;

                LeftQ.push(Lfront->left);
                LeftQ.push(Lfront->right);

                RightQ.push(Rfront->right);
                RightQ.push(Rfront->left);

                LeftQ.pop(); RightQ.pop();
            }
            else {
                return false;
            }
        }

        if (LeftQ.empty() && RightQ.empty()) return true;
        else return false;
    }
};