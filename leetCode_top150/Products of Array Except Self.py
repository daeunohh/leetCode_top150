class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        muls = [1] * len(nums)
        rev_muls = [1] * len(nums)

        for i in range(len(nums)):
            rev_i = len(nums) - 1 - i
            # print(i, rev_i)
            if i == 0:
                muls[i] = nums[i]
                rev_muls[rev_i] = nums[rev_i]
            else:
                muls[i] = nums[i] * muls[i-1]
                rev_muls[rev_i] = nums[rev_i] * rev_muls[rev_i+1]        
        # print(muls)
        # print(rev_muls)

        ret = []
        for i in range(len(nums)):
            val = 0
            prev = i - 1
            next = i + 1
            if prev < 0:
                val = rev_muls[next]
            elif next > len(nums) - 1:
                val = muls[prev]
            else:
                val = muls[prev] * rev_muls[next]
            ret.append(val)
            
        return ret