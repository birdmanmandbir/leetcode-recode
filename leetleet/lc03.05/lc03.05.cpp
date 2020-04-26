#include "lib/general.h"
class SortedStack {
private:
    stack<int> mainStk;
    stack<int> helpStk;
    int min;

public:
    SortedStack()
    {
        min = INT_MAX;
    }

    void push(int val)
    {
        if (val <= min) {
            mainStk.push(val);
            min = val;
        } else {
            while (!mainStk.empty() && mainStk.top() < val) {
                helpStk.push(mainStk.top());
                mainStk.pop();
            }
            mainStk.push(val);
            while (!helpStk.empty()) {
                mainStk.push(helpStk.top());
                helpStk.pop();
            }
        }
    }

    void pop()
    {
        if (mainStk.empty())
            return;
        mainStk.pop();
        min = mainStk.empty()? -1 : mainStk.top();
    }

    int peek()
    {
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

int main()
{
    SortedStack* obj = new SortedStack();
    obj->pop();
    obj->pop();
    obj->push(1);
    obj->pop();
    obj->isEmpty();
}