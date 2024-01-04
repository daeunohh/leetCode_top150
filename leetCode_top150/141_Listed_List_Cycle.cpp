#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != slow) {
            if (fast == NULL) return false;
            else if (fast->next == NULL) return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};



