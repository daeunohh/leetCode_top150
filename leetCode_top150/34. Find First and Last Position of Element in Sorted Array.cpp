class Solution {
public:
    int findLeft(vector<int>& nums, int n, int target) {
        int l = 0, r = n - 1, left_idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                r = mid - 1;
                left_idx = mid;//possibly my answer
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return left_idx;
    }
    int findRight(vector<int>& nums, int n, int target) {
        int l = 0, r = n - 1, right_idx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                l = mid + 1;
                right_idx = mid;//possibly my answer
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return right_idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        //onlt search the left part
        int left_most = findLeft(nums, n, target);

        //search only the right part
        int right_most = findRight(nums, n, target);

        vector<int>res;
        res.push_back(left_most);
        res.push_back(right_most);
        return res;
    }
};