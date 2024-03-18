#include "main.h"
#include <queue>



class Solution {
public:
    queue<string> q;
    vector<string> itoc;

    Solution() {
        itoc.assign(10, "");
        itoc[2] = "abc";
        itoc[3] = "def";
        itoc[4] = "ghi";
        itoc[5] = "jkl";
        itoc[6] = "mno";
        itoc[7] = "pqrs";
        itoc[8] = "tuv";
        itoc[9] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        
        for (char c : itoc[digits[0] - '0']) {
            q.push((c));
        }

        while (!q.empty()) {
            string str = q.front(); q.pop();
            if (str.length() == digits.length()) {
                ret.push_back(str);
            }
            else {
                for (char c : itoc[digits[str.length()] - '0']) {
                    string newString = str + c;
                    q.push(newString);
                }
            }
        }

        return ret;
    }
};

void main() {
    Solution s;
    s.letterCombinations("23");
}
