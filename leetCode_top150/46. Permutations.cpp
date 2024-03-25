#include "main.h"

class Solution {
public:
    void func(vector<int>& nums, int index, vector<vector<int>>& ret) {
        if (index == nums.size())
            ret.push_back(nums);
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            func(nums, index + 1, ret);
            swap(nums[i], nums[index]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {     
        vector<vector<int>> ret;
        func(nums, 0, ret);
        return ret;
    }
};