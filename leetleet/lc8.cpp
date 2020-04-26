#include <climits>
#include <iostream>
#include <string>
using namespace std;
// https://leetcode-cn.com/problems/string-to-integer-atoi/solution/jin-liang-bu-shi-yong-ku-han-shu-nai-xin-diao-shi-/
// 尽量不使用库函数、一次遍历
int myAtoi(string str)
{
    int index = 0;
    int n = str.size();
    // 这里不能使用long，是题目要求
    int result = 0;
    // 先去除开头空格
    while (index < n) {
        if (str[index] == ' ') {
            index++;
        } else {
            break;
        }
    }
    // 判断符号
    int sign = 1;
    if (str[index] == '-') {
        sign = -1;
    }
    if (str[index] == '-' || str[index] == '+') {
        index++;
    }
    // 开始判断数字
    while (index < n) {
        char curc = str[index];
        if (curc > '9' || curc < '0') {
            break;
        }
        // 通过这种方式避免了判断过程中越界
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (curc - '0') >= INT_MAX % 10)) {
            return INT_MAX;
        }
        // 注意不能用-INT_MIN % 10, 会直接overflow
        if (result < INT_MIN / 10 || (result == INT_MIN / 10 && (curc - '0') >= -(INT_MIN % 10))) {
            return INT_MIN;
        }
        result = result * 10 + sign * (curc - '0');
        index++;
    }
    return result;
}
int main(){
    cout<<myAtoi("42");
}