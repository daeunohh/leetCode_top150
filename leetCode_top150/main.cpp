#include "main.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return { -1, -1 };

        int start = 0; int end = nums.size() - 1;
        int mid = 0;
        int retStart = -1; int retEnd = -1;

        while (start <= end) {
            if (nums[start] == target) {
                retStart = start;
            }
            if (nums[end] == target) {
                retEnd == end;
            }
            if (retStart != -1 && retEnd != -1) return { retStart, retEnd };

            mid = (end + start) / 2;
            if (nums[mid] == target) {

            }
            else {

            }




        }

        return { -1, -1 };
    }
};



