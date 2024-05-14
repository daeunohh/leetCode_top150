class Solution {
public:

    class Heap{
        struct Node{
            int value;
            Node* left= nullptr;
            Node* right = nullptr;
        };

        Node* head = nullptr;

        Heap(int val){
            head = new Node();
            head->value = val;
        }
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
    }
};