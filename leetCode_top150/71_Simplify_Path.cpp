#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <stack>
using namespace std;

class Solution {
public:
    bool isLetter(const char& byte) {
        if ('a' <= byte && byte <= 'z') return true;
        else if ('A' <= byte && byte <= 'Z') return true;
        else if ('0' <= byte && byte <= '9') return true;
        else if (byte == '_') return true;
        return false;
    }

    string makeString(stack<string>& v) {
        if (v.empty()) return "/";

        string newString;
        while (!v.empty()) {
            newString = "/" + v.top() + newString; v.pop();
        }

        return newString;
    }

    bool haveWordToInsert(const string::iterator& it, const string& path) {
        return it != path.end();
    }

    int getDotCnt(string::iterator it, const string& path) {
        int cnt = 0;
        while (it != path.end()) {
            if (*it == '.') {
                cnt++; it++;
            }
            else return cnt;
        }
        return cnt;
    }

    string simplifyPath(string path) {
        // '.' refers to the current directory,
        // ..' refers to the directory up a level, 
        // multiple slashes (i.e. '//') are treated as a single slash '/'
        // '...' are treated as file/directory names.

        // The path starts with a single slash '/'.
        // Any two directories are separated by a single slash '/'.
        // The path does not end with a trailing '/'.
        // The path only contains the directories on the path from the root directory 
        // to the target file or directory 
        // (i.e., no period '.' or double period '..')

        vector<string> strs;

        for (auto it = path.begin(); it != path.end(); ) {
            while (it != path.end() && *it == '/') it++;
            if (it == path.end()) break;

            auto start = it; auto last = it;
            while (last != path.end() && *last != '/') last++;

            strs.push_back(string(start, last));
            it = last;
        }

        stack<string> strV;

        for (string& s : strs) {
            if (strcmp(s.c_str(), ".") == 0) continue;
            else if (strcmp(s.c_str(), "..") == 0) {
                if (!strV.empty()) strV.pop();
            }
            else strV.push(s);
        }

        return makeString(strV);
    }
};