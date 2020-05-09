# 作者：Amazing_J
# 链接：https://www.nowcoder.com/discuss/408980?type=all&order=time&pos=&page=1
# 来源：牛客网
import sys
if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    line = sys.stdin.readline().strip()
    values = list(map(int, line.split()))
    values.sort()
    res = []
    tag = 1
    for i in range(len(values)):
        if tag == 1:
            res.append(values.pop(-1))
            tag = 0
        elif tag == 0:
            res.append(values.pop(0))
            tag = 1
    sum = 0
    for i in range(len(res)):
        if i == 0:
            sum += abs(res[i] - res[1])
            sum += abs(res[i] - res[-1])
        elif i == len(res) - 1:
            sum += abs(res[i]-res[0])
            sum += abs(res[i]-res[i-1])
        else:
            sum += abs(res[i]-res[i-1])
            sum += abs(res[i] - res[i+1])
    print(sum//2)
    for i in res:
        print(str(i)+' ', end='')
