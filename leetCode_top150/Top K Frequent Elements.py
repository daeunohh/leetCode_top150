# Time:N, Space:N+N+M
import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count = dict()
        for num in nums:
            count[num] = count.get(num, 0) + 1
        print(count)

        frequency = [[] for i in range(len(nums) + 1)] 
        for key, value in count.items():
            frequency[value].append(key)
        
        ret = []
        for i in range(len(frequency) - 1, -1, -1):
            ret += frequency[i]
            if len(ret) == k:
                return ret
        return []


        