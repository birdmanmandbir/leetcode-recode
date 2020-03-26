#include <iostream>
#include <stack>
using namespace std;
void printArray(int*, int);
// https://www.nowcoder.com/question/next?pid=21283868&qid=830860&tid=31934642
// 腾讯2020校园招聘-后台
// record: 一开始只通过60%测试样例, 对比其他人的代码后发现是边界没有处理,
// 对于相同高度的楼一样按看不到处理
void getResult(int* a, int* b, int n){
    // 自顶向下递增, 应从右往左看
    int front[n];
    int back[n];
    stack<int> sIncrease;
    for(int i=n-1;i>=0;i--){
        back[i]=sIncrease.size();
        while(!sIncrease.empty() && sIncrease.top()<=a[i]){
            sIncrease.pop();
        }
        sIncrease.push(a[i]);
    }
    stack<int> sDecrease;
    for(int i=0;i<n;i++){
        front[i]=sDecrease.size();
        while(!sDecrease.empty() && sDecrease.top()<=a[i]){
            sDecrease.pop();
        }
        sDecrease.push(a[i]);
    }
    // calculate result
    for(int i=0;i<n;i++){
        b[i]=front[i]+1+back[i];
    }
}

void printArray(int* a, int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // for(int building:a){
    //     cin>>building;
    // }
    int b[n]; // result
    getResult(a,b,n);
    printArray(b, n);

}