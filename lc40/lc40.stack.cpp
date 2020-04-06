// 由于题目给出的形状和括号类似, 所以想到用栈解决:
// 经测试, 实际上栈和dp区别不大, 但栈的设计难度更高
int trap(vector<int>& height)
{
    int ans = 0;
    int n = height.size();
    stack<int> sk;
    // 先找到第一个最左位置
    int index = 0;
    while (index < n) {
        while (!sk.empty() && height[sk.top()] < height[index]) {
            // 左小于右
            int top = sk.top();
            sk.pop();
            // 对sk有直接操作的语句后面判断是否为空, 如果为空, 说明左边没有更高的墙, 则break;
            if (sk.empty()) {
                break;
            }
            // 左边有更高的墙, 所以计算水量
            int distance = index - sk.top() - 1;
            int myHeight = min(height[index], height[sk.top()]) - height[top];
            ans += distance * myHeight;
        }
        sk.push(index++);
    }
    return ans;
}