#include "lib/general.h"
// https://leetcode-cn.com/problems/min-stack/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-38/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
        sk.push(x);
        if (helpSk.empty() || helpSk.top() >= x){
            helpSk.push(x);
        }
    }

    void pop() {
        if (helpSk.top() == sk.top()){
            helpSk.pop();
        }
        sk.pop();
    }

    int top() {
        return sk.top();
    }

    int min() {
        return helpSk.top();
    }
private:
    stack<int> sk;
    stack<int> helpSk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
int main(){
    MinStack sk;
    sk.push(0);
    sk.push(1);
    sk.push(0);
    sk.min();
    sk.pop();
    sk.min();
}