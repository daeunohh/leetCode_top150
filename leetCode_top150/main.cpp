#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            auto front = nums.begin();
            auto tail = nums.end() - 1;
            auto idx = tail;

            while(distance(front, tail) >= 0){
                auto mid = front + (distance(front, tail) / 2);
                // cout << distance(nums.begin(), front) << " " << distance(nums.begin(), tail) << " " << distance(nums.begin(), mid) << endl;
                if(*mid == target) return distance(nums.begin(), mid);
                if(*mid < target){
                    front = mid + 1;
                }
                else{
                    if(mid == nums.begin()){
                        return 0;
                    }
                    tail = mid - 1;
                    idx = mid;
                }
            }
            if(idx == tail){
                return nums.size();
            }
            return distance(nums.begin(), idx);
        }
    };