#include "main.h"

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            set<int> multiple;
            set<int> once;

            for(int i=0; i<nums.size(); i++){
                int n = nums[i];
                if(multiple.find(n) != multiple.end()){
                    continue;
                }
                if(once.find(n) != once.end()){
                    once.erase(n);
                    multiple.insert(n);
                    continue;
                }
                once.insert(n);
            }

            auto it = once.begin();
            cout << (*it) << endl;
        }
    };