package ali413;
import java.util.Scanner;
// 作者：Loven166888
// 链接：https://www.nowcoder.com/discuss/409192?type=all&order=time&pos=&page=1
// 来源：牛客网

// 第一题：选动物老大，n个小动物，编号1-n,代表武力值，值越小，武力值越高，每个小动物都有一票投票权，可以投给自己或者自己崇拜的动物，或者和自己崇拜的动物跟票。只能崇拜武力值比自己厉害的动物。
// 输入样例：第一行动物个数， 第二行崇拜对象。
// 4
// 0 1 1 1
// 输出
// 4
// 1
// 1
// 1


// 题解
// 据题意, 动物已经按武力值排序, 所以要利用单调性, 从右往左判断
// 输出为最大投票数?
public class p1 {
    // 作者：Loven166888
    // 链接：https://www.nowcoder.com/discuss/409192?type=all&order=time&pos=&page=1
    // 来源：牛客网

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] an = new int[n];
        int[] pow = new int[n + 1]; // 为方便动态规划
        for(int i = 0; i < n; i++){
            an[i] = scanner.nextInt();
        }
        for (int i = an.length - 1; i >= 0; i--) {
            if(an[i] == 0){
                continue;
            }
            pow[an[i]] = pow[an[i]] + pow[i + 1] + 1;
            // pow[an[i]]: 原有的
            // pow[i + 1]: 其他动物跟投 + 当前崇拜an[i]的动物
            // 1: 自己
        }
        for (int i = 1; i < pow.length; i++) {
            System.out.println(pow[i] + 1);
        }
        scanner.close();
    }
}