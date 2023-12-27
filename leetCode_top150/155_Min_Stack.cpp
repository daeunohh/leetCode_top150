#include <vector>
#include <list>
using namespace std;

class MinStack {
    struct P {
        int val;
        list<int>::iterator it;
    };

public:
    vector<P> stack;
    vector<P>::iterator last;

    list<int> sortList;

    MinStack() : last(stack.end()) {
    }

    list<int>::iterator pushInSortList(int val) {
        if (sortList.empty()) {
            sortList.push_back(val);
            return sortList.begin();
        }
        auto it = sortList.begin();
        while (it != sortList.end() && *it > val) ++it;
        return sortList.insert(it, val);
    }

    void push(int val) {
        auto it = pushInSortList(val);

        if (last == stack.end()) {              // 1. when the vector is empty
            stack.clear();
            stack.push_back({ val, it });
            last = stack.begin();
            return;
        }

        if (last == stack.end() - 1) {
            stack.push_back({ val, it });
            last = stack.end() - 1;
            return;
        }

        last++;
        *last = { val, it };
    }

    void pop() {
        sortList.erase(last->it);
        if (last == stack.begin()) last = stack.end();
        else --last;
    }

    int top() {
        return last->val;
    }

    int getMin() {
        return *(--sortList.end());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */