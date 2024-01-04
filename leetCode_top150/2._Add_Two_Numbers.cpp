class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* firstl1 = l1;
        ListNode* firstl2 = l2;

        int Carry = 0;

        while (1) {
            int sum = l1->val + l2->val + Carry;

            Carry = sum / 10;
            sum %= 10;

            l1->val = sum;

            if (l1->next == nullptr || l2->next == nullptr) break;

            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1->next != nullptr || l2->next != nullptr) {
            if (l2->next != nullptr) {
                l1->next = l2->next;
            }
            l1 = l1->next;

            while (Carry != 0) {
                l1->val += Carry;
                Carry = l1->val / 10;
                l1->val = l1->val % 10;

                if (l1->next == nullptr) break;
                l1 = l1->next;
            }
        }

        if (Carry != 0) {
            l1->next = new ListNode(Carry);
        }

        return firstl1;
    }
};