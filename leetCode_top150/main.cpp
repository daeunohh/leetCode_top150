#include "main.h"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int totalMax = nums[0];
		int prevMax = totalMax;

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > prevMax + nums[i]) {
				prevMax = nums[i];
			}
			else {
				prevMax = prevMax + nums[i];
			}

			if (prevMax > totalMax) totalMax = prevMax;
		}

		return totalMax;
    }
};




