cpp stack.top() 对于int不会返回-1, 需要提前判断.

## 剑指offer
### 9
1.添加元素直接添加； 2.删除元素时判断第二个栈是不是空，是的话一次性将第一个栈元素全部压入，再删除就可以了 3.删除时如果第二个栈不空，那直接弹出就可以了。
https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/solution/mian-shi-ti-09yong-liang-ge-zhan-shi-xian-dui-lie-/


### 10-1
取余运算规则 (a + b) % p = (a % p + b % p) % p
由递归式可得：F(N) % 1e9+7 = (F(N-1)%1e9+7 + F(N-2)%1e9+7) % 1e9+7
数组中存储取余后的结果，最后直接返回dp[n]即可。

作者：jesse-42
链接：https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/ji-yi-hua-sou-suo-shuang-bai-tong-guo-by-jesse-42/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

### 10-2
最后一步要么是2, 要么是1, 对于1或2只是一个选择
所以dp[n]=dp[n-1]+dp[n-2]

### 62
约瑟夫环， 仍然不太懂

## TODO
https://leetcode-cn.com/problems/number-of-atoms/ 应该是递归或者递归模拟栈, 大写字母是元素开头, 数字是结尾

岛屿数量-并查集

nonRecurPostOrderV2(2个栈实现)
https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/


lc4 两个有序数组的中位数
https://leetcode-cn.com/problems/median-of-two-sorted-arrays/

lc50 快速幂算法 - 递归
## Notes
1. 处理边界情况
2. 建模找考点；注意要在纸上模拟下过程
3. 写代码
4. 测试

n&(n-1)==0 优先计算等号, 需要在左边加括号才能有预期行为

递归时参数用形参(引用), 不要用实参, 空间时间占用更小.

[尾递归](https://www.zhihu.com/question/20761771)

碰到子序列问题可以考虑先调整整个数列， 因为子序列一般不受原顺序影响
- lc5376 https://leetcode-cn.com/problems/minimum-subsequence-in-non-increasing-order/solution/c-mo-ni-jiu-wan-shi-liao-by-time-limit/



vector.push_back 放进去的是参数的拷贝，这个特性很重要


>vector::void push_back (const value_type& val);
>
>vector::void push_back (value_type&& val);
>
>该函数将一个新的元素加到vector的最后面，位置为当前最后一个元素的下一个元素，新的元素的值是val的拷贝（或者是移动拷贝）
>
>————————————————
>
>版权声明：本文为CSDN博主「稚枭天卓」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
>原文链接：https://blog.csdn.net/u013630349/java/article/details/46853297