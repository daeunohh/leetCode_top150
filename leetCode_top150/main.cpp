#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            for(auto it = nums.begin(); it != nums.end(); it++){
                if(*it >= target){
                    return distance(nums.begin(), it);
                }
            }
            return nums.size();
        }
    };