#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
  };
 
class Solution {
    const int DUMMY = 100009;

public:
    bool hasCycle(ListNode* head) {
        ListNode* now = head;
        while (1) {
            if (now->next == NULL) {
                return false;
            }
            if (now->next->val == DUMMY) {
                return true;
            }
            now->val = DUMMY;
            now = now->next;
        }
        return true;
    }
};




