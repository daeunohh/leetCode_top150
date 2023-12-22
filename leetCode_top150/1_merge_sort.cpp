class Solution {

public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if(m == 0) {

            nums1 = nums2;

            return;

        }

        if(n == 0) return;

        bool isEnd2End = false;

        auto end = nums1.end() - 1;

        auto end1 = nums1.begin() + m - 1;

        auto end2 = nums2.end() - 1;

​

        while(1){

            if(*end1 > *end2){

                *end = *end1;

                end--;

                if(end1 == nums1.begin()) break;

                else end1--;

            }

            else{

                *end = *end2;

                end--;

                if(end2 == nums2.begin()) {

                    isEnd2End = true;

                    break;

                }

                else end2--;

            }

        }

​

        if(isEnd2End == true) return;

        int cnt = distance(nums1.begin(), end) + 1;

        for(int i = 0;i < cnt;i++){

            *end = *end2;

            end--; end2--;

        }

    }

};
