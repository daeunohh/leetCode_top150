// #include "main.h"
const int MIN = -1001;

class Solution {
public:
    struct Node {
        Node* left= nullptr;
        Node* right = nullptr;
        int val = MIN; int cnt = 0;

        Node(int _val) : left(nullptr), right(nullptr), val(_val), cnt(1) {}
    };

    int k = 0;
    Node* head = nullptr;

    void makeTree(vector<int>& nums) {
        for (auto n : nums) {
            if (head == nullptr) {
                head = new Node(n);
                continue;
            }

            Node* cur = head;
            while (1) {
                if (cur->val == n) {
                    cur->cnt++;
                    break;
                }

                if (cur->val > n) {
                    if (cur->left == nullptr) {
                        cur->left = new Node(n);
                        break;
                    } else {
                        cur = cur->left;
                    }
                } else {
                    if (cur->right == nullptr) {
                        cur->right = new Node(n);
                        break;
                    }
                    else {
                        cur = cur->right;
                    }
                }
            }
        }
    }

    int cnt = 0; int kthVal = MIN;
    void searchKth(Node* cur) {
        if (cur->right != nullptr) {
            searchKth(cur->right);
        }

        if (kthVal == MIN) {
            cnt += cur->cnt;
            printf("%d %d %d \n", cur->val, cur->cnt, cnt);
            if (cnt >= k) {
                kthVal = cur->val;
                return;
            }
        }
        else return;

        if (kthVal == MIN && cur->left != nullptr) {
            searchKth(cur->left);
        }
        else return;
    }

    int findKthLargest(vector<int>& nums, int k) {
        this->k = k;

        makeTree(nums);
        searchKth(head);

        return kthVal;
    }
};


