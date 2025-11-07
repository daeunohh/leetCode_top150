class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        hq = []
        for n in nums:
            heapq.heappush(hq, n)
        
        last = heapq.heappop(hq)
        cnt = 1
        longest = 1
        
        while len(hq) != 0 :
            n = heapq.heappop(hq)
            if n == last:
                continue
            if n == last + 1:
                last = n
                cnt += 1
            else:
                longest = max(longest, cnt)
                last = n
                cnt = 1
            # print(n)
        longest = max(longest, cnt)
        
        return longest
        