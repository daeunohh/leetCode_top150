#include "main.h"


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret; 
        priority_queue < pair<int, pair<int, int>>> pq; 

        int i1 = 0; int i2 = 0;
        ret.push_back({ nums1[0], nums2[0] });

        while (ret.size() < k) {

            if ((i1 == nums1.size() - 1) || (i2 == nums2.size() - 1)) {
                if (i1 == nums1.size() - 1) {
                    ret.push_back({ nums1[i1], nums2[i2 + 1] });
                    i2++;
                    continue;
                }
                else { // (i2 == nums2.size() - 1)
                    ret.push_back({ nums1[i1 + 1], nums2[i2] });
                    i1++;
                    continue;
                }
            }

            if ((nums1[i1] + nums2[i2 + 1]) < (nums1[i1 + 1] + nums2[i2])) {
                ret.push_back({ nums1[i1], nums2[i2 + 1] });
                i2++;
            }
            else {
                ret.push_back({ nums1[i1 + 1], nums2[i2]} );
                i1++;
            }
        }

        return ret;
    }
};

