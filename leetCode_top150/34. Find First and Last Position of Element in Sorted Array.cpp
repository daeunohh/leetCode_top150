#include "main.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return { -1, -1 };

        int start = 0; int end = nums.size() - 1;
        int mid = 0;

        while (start <= end) {
            mid = (end + start) / 2;
            if (nums[mid] == target) {
                break;
            }

            if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        if (nums[mid] == target) {
            start = mid - 1; end = mid + 1;
            while (start >= 0 && nums[start] == target) start--;
            while (end < nums.size() && nums[end] == target) end++;
            return { start + 1, end - 1 };
        }

        return { -1, -1 };
    }
};