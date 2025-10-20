# Time: M* NlogN, Space:N 
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hashmap = {}
        for i in range(len(strs)):
            sortedstr = str(sorted(strs[i]))
            hashmap[sortedstr] = hashmap.get(sortedstr, []) + [i]

        ret = []
        for comb in hashmap:
            idxs = hashmap[comb]
            tmp = []
            for idx in idxs:
                tmp.append(strs[idx])
            ret.append(tmp)

        return ret
