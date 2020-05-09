package tencent;
import java.util.Scanner;
public class Main3 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] order = new int[n];
        int[] statu = new int[n];
        //  int[] index = new int[n];
        for(int i = 0 ; i < n ; i++){
            int tmp = in.nextInt();
            a[i] = tmp;
            order[i] = tmp;
            statu[i] = 1;
            //index[i] = i;
        }
        for(int i = 0 ; i < n ; i++){
            b[i] = in.nextInt();
        }
        // begin
        int count = 0;
        while(true){
            int tmp_count = 0;
            for(int i = 0; i < n-1 ;i++){
                if(order[i] > order[i+1]){
                    int ai = a[i];
                    a[i] = a[i+1];
                    a[i+1] = ai;
                    int bi = b[i];
                    b[i] = b[i+1];
                    b[i+1] = bi;
                    int si = statu[i];
                    statu[i] = statu[i+1];
                    statu[i+1] = si;
                    if(statu[i] == 1){
                        statu[i] = 0;
                        order[i] = b[i];
                    }else{
                        statu[i] = 1;
                        order[i] = a[i];
                    }
                    if(statu[i+1] == 1){
                        statu[i+1] = 0;
                        order[i+1] = b[i+1];
                    }else{
                        statu[i+1] = 1;
                        order[i+1] = a[i+1];
                    }
                    tmp_count += 1;
                }
            }
            count += tmp_count;
            if(tmp_count == 0){
                break;
            }
        }
        System.out.println(count);
    }
}
