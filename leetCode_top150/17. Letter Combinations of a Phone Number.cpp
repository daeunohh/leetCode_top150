#include "main.h"
#include <queue>

class Solution {
public:
    queue<string> q;
    vector<vector<string>> itoc;

    Solution() {
        itoc.assign(10, {});
        itoc[2] = { "a", "b", "c" };
        itoc[3] = { "d", "e", "f" };
        itoc[4] = { "g", "h", "i" };
        itoc[5] = { "j", "k", "l" };
        itoc[6] = { "m", "n", "o" };
        itoc[7] = { "p", "q", "r", "s" };
        itoc[8] = { "t", "u", "v" };
        itoc[9] = { "w","x", "y", "z" };
    }

    vector<string> letterCombinations(string digits) {
        int digitLen = digits.length();
        if (digits.empty()) return {};
        vector<string> ret;
        
        for (string c : itoc[digits[0] - '0']) {
            q.push((c));
        }

        while (!q.empty()) {
            string str = q.front(); q.pop();
            if (str.length() == digitLen) {
                ret.push_back(str);
            }
            else {
                for (string c : itoc[digits[str.length()] - '0']) {
                    q.push(str + c);
                }
            }
        }

        return ret;
    }
};

void main() {
    Solution s;
    s.letterCombinations("");
}
