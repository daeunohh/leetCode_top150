

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return { -1, -1 };

        int retStart = -1; int retEnd = -1;
        {
            int start = 0; int end = nums.size() - 1;
            int mid = 0;

            while (start <= end) {
                mid = (end + start) / 2;
                if (nums[mid] == target) {
                    if (mid == 0 || nums[mid - 1] != target) {
                        retStart = mid; break;
                    }
                }
                if (nums[mid] >= target) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        {
            int start = 0; int end = nums.size() - 1;
            int mid = 0;

            while (start <= end) {
                mid = (end + start) / 2;
                if (nums[mid] == target) {
                    if (mid == nums.size() - 1 || nums[mid + 1] != target) {
                        retEnd = mid; break;
                    }
                }
                if (nums[mid] > target) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }

        if (retStart != -1 && retEnd != -1) return { retStart, retEnd };


        return { -1, -1 };
    }
};