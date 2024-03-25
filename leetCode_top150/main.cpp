#include "main.h"

class Solution {
public:
    vector<vector<int>> ret;
    vector<bool> included;
    vector<int> current;

    void func(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (!included[i]) {
                current.push_back(nums[i]); included[i] = true;
                func(nums);
                current.pop_back(); included[i] = false;
            }
        }
        if(current.size() == nums.size())
            ret.push_back(current);
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        included.assign(nums.size(), false);
        
        func(nums);

        return ret;
    }
};