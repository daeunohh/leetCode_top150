class Solution {
public:
    struct CMP {
        bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            if (a.first == b.first) {
                if (a.second.first == b.second.first) {
                    return a.second.second > b.second.second;
                }
                else return a.second.first > b.second.first;
            }
            else return b.first < a.first;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret; 
        priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, CMP> pq;
        set<pair<int, int>> visited;

        pq.push({ nums1[0] + nums2[0] , {0, 0} });
        visited.insert({ 0, 0 });

        while (1) {
            auto smallest = pq.top().second; pq.pop();
            int i1 = smallest.first; int i2 = smallest.second;
            ret.push_back({ nums1[i1], nums2[i2] });
            if (ret.size() == k) break;

            // cout << i1 << " " << i2 << " " << endl;

            if ((i1 == nums1.size() - 1) || (i2 == nums2.size() - 1)) {
                if ((i1 == nums1.size() - 1) && (i2 == nums2.size() - 1)) continue;
                
                if (i1 == nums1.size() - 1) {
                    if (visited.find({ i1, i2 + 1 }) == visited.end()) {
                        pq.push({ nums1[i1] + nums2[i2 + 1], {i1 , i2 + 1} });
                        visited.insert({ i1, i2 + 1 });
                    }
                    continue;
                }
                else { // (i2 == nums2.size() - 1)
                    if (visited.find({ i1 + 1, i2 }) == visited.end()) {
                        pq.push({ nums1[i1 + 1] + nums2[i2], {i1 + 1 , i2} });
                        visited.insert({ i1 + 1, i2 });
                    }
                    continue;
                }
            }

            if (visited.find({ i1, i2 + 1 }) == visited.end()) {
                pq.push({ nums1[i1] + nums2[i2 + 1], {i1 , i2 + 1} });
                visited.insert({ i1, i2 + 1 });
            }

            if (visited.find({ i1 + 1, i2 }) == visited.end()) {
                pq.push({ nums1[i1 + 1] + nums2[i2], {i1 + 1 , i2} });
                visited.insert({ i1 + 1, i2 });
            }
        }

        return ret;
    }
};

