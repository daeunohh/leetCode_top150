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
                // search frontward part
                int fstart = start; int fend = mid;
                int fmid = (fend + fstart) / 2;
                while (fstart <= fend) {
                    fmid = (fend + fstart) / 2;
                    if (nums[fmid] == target) {
                        fend = fmid - 1;
                    }
                    else {
                        fstart = fmid + 1;
                    }
                }

                // search backward part
                int bstart = mid; int bend = end;
                int bmid = (bend + bstart) / 2;
                while (bstart <= bend) {
                    bmid = (bend + bstart) / 2;
                    if (nums[bmid] == target) {
                        bstart = bmid + 1;
                    }
                    else {
                        bend = bmid - 1;
                    }
                }

                return { fstart, bend };
            }

            if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return { -1, -1 };
    }
};