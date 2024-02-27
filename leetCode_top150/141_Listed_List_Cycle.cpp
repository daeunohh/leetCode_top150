#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(0) {}
  };

////////////////////////////////////////////////////////////

class Solution {
public:
    ListNode* mergeSort(ListNode* a, ListNode* b) {
        ListNode* ret = new ListNode(0); 
        ListNode* retHead(ret);

        while (a != nullptr && b != nullptr) {
            if (a->val < b->val) {
                ret->next = a;
                a = a->next;
                ret = ret->next;
            }
            else {
                ret->next = b;
                b = b->next;
                ret = ret->next;
            }
        }
        if (a != nullptr) {
            ret->next = a;
        }
        if(b != nullptr) {
            ret->next = b;
        }

        return retHead->next;
    }

    ListNode* sortList(ListNode* head) {
        vector<ListNode*> nodeList;
        auto p = head;
        nodeList.push_back(p);

        while (p != nullptr) {
            if (p->next == nullptr) {
                break;
            }

            if (p->next->val < p->val) {
                auto pre = p;
                p = p->next;
                pre->next = nullptr;
                nodeList.push_back(p);
            }
            else {
                p = p->next;
            }
        }

        auto res = nodeList[0];
        for (int i = 1; i < nodeList.size(); i++) {
            res = mergeSort(res, nodeList[i]);
        }

        return res;
    }
};




