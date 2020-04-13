#include "../lib/general.h"
// https://leetcode-cn.com/problems/sort-of-stacks-lcci/solution/java-shuang-zhan-duo-xing-geng-xin-17ms-9938-by-la/
// after use laze update,488ms ->24ms
class SortedStack {
private:
    stack<int> mainStk;
    stack<int> helpStk;

public:
    void push(int val)
    {
        while (true) {
            // INT_MAX could ensure first check helpStk when mainStk is empty
            int mainTop = mainStk.empty() ? INT_MAX : mainStk.top();
            int helpTop = helpStk.empty() ? INT_MIN : helpStk.top();
            if (val > mainTop) {
                helpStk.push(mainStk.top());
                mainStk.pop();
            } else if (val < helpTop) {
                mainStk.push(helpStk.top());
                helpStk.pop();
            } else {
                mainStk.push(val);
                break;
            }
        }
    }

    void pop()
    {
        while (!helpStk.empty()) {
            mainStk.push(helpStk.top());
            helpStk.pop();
        }
        if (mainStk.empty())
            return;
        mainStk.pop();
    }

    int peek()
    {
        while (!helpStk.empty()) {
            mainStk.push(helpStk.top());
            helpStk.pop();
        }
        if (mainStk.empty())
            return -1;
        return mainStk.top();
    }

    bool isEmpty()
    {
        return mainStk.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
