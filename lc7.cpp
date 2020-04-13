#include "lib/general.h"
// 很棒的设计，将数看成字符串并封装两个操作为方法
// https://leetcode-cn.com/problems/reverse-integer/solution/zheng-shu-fan-zhuan-by-leetcode/
// @lc app=leetcode.cn id=7 lang=cpp
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x){
            int popResult = pop(x);
            if (!push(result, popResult)){
                return 0;
            }
        }
        return result;
    }
    int pop(int& x){
        int popResult = x%10;
        x/=10;
        return popResult;
    }
    bool push(int& x, int valueToPush){
        if(x>INT_MAX/10 || x==INT_MAX/10 && valueToPush>INT_MAX%10)return false;
        if(x<INT_MIN/10 || x==INT_MIN/10 && valueToPush>-(INT_MIN%10))return false;
        x = x*10+valueToPush;
        return true;
    }
};