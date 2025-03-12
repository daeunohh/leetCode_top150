#include "main.h"


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> ret;

        int idx = 0;
        while (1) {
            int idx1 = 0; int idx2 = 0;
            if (idx < nums1.size()) idx1 = idx; 
            else idx1 = nums1.size();
            if (idx < nums2.size()) idx2 = idx; 
            else idx2 = nums2.size();

            if (idx != 0) {
                for (int i = 0; i < idx2; i++) {
                    pq.push({ -(nums1[idx1] + nums2[i]), {idx1, i} });
                }
                for (int i = 0; i < idx1; i++) {
                    pq.push({ -(nums1[i] + nums2[idx2]), {i, idx2} });
                }
            }            
            pq.push({ -(nums1[idx1] + nums2[idx2]), {idx1, idx2} });
            idx++;

            if (pq.size() >= k) break;
        }

        for (int i = 0; i < k; i++) {
            pair<int, pair<int, int>> smallestPair = pq.top(); pq.pop();
            ret.push_back({ nums1[smallestPair.second.first], nums2[smallestPair.second.second] });
        }

        return ret;
    }
};

