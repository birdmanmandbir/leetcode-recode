# 作者：小xiao2018
# 链接：https://www.nowcoder.com/discuss/402909?type=all&order=time&pos=&page=1
# 来源：牛客网
# n : time of attack
# m : number of enemies
# a : HP of enemy
# b : how much enemies I could attack
# min(n*b/a, m)


# https://www.nowcoder.com/discuss/402909?type=all&order=time&pos=&page=1
data = list(map(int,input().split()))
T = data[0]

for _ in range(T):
    [n,m,a,b] = list(map(int,input().split()))
    if n<a:
        print(0)
        continue
    print(min(n*b//a, m)) # // : 整除