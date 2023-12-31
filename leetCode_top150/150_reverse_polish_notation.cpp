#include vector
#include string
#include iostream
using namespace std;

struct p {
    int val;     계산 결과
    int i;       계산된 마지막 index
};


class Solution {
    vectorstring dummy;
    vectorstring& Tokens = dummy;

    bool isNumeric(const string& s) {
        if ('0' = s.back() && s.back() = '9') {
            return true;
        }
        return false;
    }
    
    int toInt(const string& s) {
        int intVal = 0; int ten = 1;
        for (auto c = s.rbegin(); c != s.rend(); ++c) {
            if (c == '-') {
                intVal = -1; break;
            }
            intVal += int(c - '0')  ten;
            ten = 10;
        }
        return intVal;
    }

    p func(int i) {
        string first = Tokens[i];
        if (isNumeric(first)) {
            return { toInt(first), i };
        }

        int secondInt = 0;
        string second = Tokens[i - 1];
        int third = 0;
        if (!isNumeric(second)) {
            auto ret2 = func(i - 1);
            secondInt = ret2.val;
            i = min(i, ret2.i);
            
            auto ret3 = func(ret2.i - 1);
            third = ret3.val;
            i = min(i, ret3.i);
        }
        else {
            secondInt = toInt(second);
            auto ret3 = func(i - 2);
            third = ret3.val;
            i = min(i, ret3.i);
        }

        if (first == +) {
            return { third + secondInt, i };
        }
        else if (first == -) {
            return { third - secondInt, i };
        }
        else if (first == ) return { third  secondInt, i };
        else return { third  secondInt, i };
    }

public
    int evalRPN(vectorstring& tokens) {
        Tokens = tokens;
        return func(tokens.size() - 1).val;
    }
};

int main() {
    Solution s;
    vectorstring v = { 10,6,9,3,+,-11,,,,17,+,5,+ };
    cout  s.evalRPN(v);
}