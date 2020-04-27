#include <bits/stdc++.h>
using namespace std;

int realDepth(int x){
    int depth = 0;
    while(x>0){
        x/=2;
        depth++;
    }
    return depth;
}

int myDepth(int x)
{
    return static_cast<int>((log(x) / log(2))) + 1;
}

int main(){
    // for (int i = 1; i <= 1000000000; i++){
    //     if (realDepth(i)!=myDepth(i)){
    //         cout << i << endl;
    //     }
    // }
    // cout << LONG_MAX - pow(10,18) << endl;
    // cout << INT_MAX << endl;


    // cout << realDepth(10) << endl;
    // cout << static_cast<int>(10) << endl;
    cout << static_cast<int>((log(pow(10,18)) / log(2)) + 1) << endl;
}