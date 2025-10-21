# Time: encode: N, decode:N
# Space: 
class Solution:
    def encode(self, strs: List[str]) -> str:
        header = ",".join(str(len(s)) for s in strs) + ","
        encoded = "".join(strs)
        return str(len(strs)) + "," + header + encoded

    def decode(self, s: str) -> List[str]:
        # print(s)
        parts = s.split(",", 1)
        num_strs = int(parts[0])
        rest = parts[1]

        header_split = rest.split(",", num_strs)
        lens = list(map(int, header_split[:num_strs]))
        # print(lens)
        encoded = header_split[-1]
        # print(encoded)

        res, i = [], 0
        for l in lens:
            res.append(encoded[i:i+l])
            i += l
        # Get len of strs
        # i = 0
        # len_strs = ""
        # while(1):
        #     if i > len(s) - 1:
        #         break
        #     if s[i] == ",":
        #         i += 1
        #         break
        #     len_strs += s[i]
        #     i += 1
        # len_strs = int(len_strs)
        # # print(len_strs, i)

        # # get lens of each str
        # lens = []
        # n = ""
        # cnt = 0
        # while(i < len(s)):
        #     if s[i] == ',':
        #         lens.append(n)
        #         cnt += 1
        #         if cnt >= len_strs:
        #             break
        #         n = ""
        #     else:
        #         n += s[i]
        #     i += 1
        # i += 1
        # # print(lens, i)

        # # get strings from s
        # ret = []
        # for l in lens:
        #     l = int(l)
        #     subs = ""
        #     for j in range(i, i+l):
        #         subs += s[j]
        #         # print(s[j])
        #     i += l
        #     ret.append(subs)
            # print(subs)

        return res
