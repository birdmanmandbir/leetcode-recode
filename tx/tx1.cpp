#include <stack>
#include <string>
#include <queue>
#include <math.h>
#include <iostream>
using namespace std;
int ctoi(char c){
    return (int)c-48;
}
int main(){
    string s;
    stack<char> sk;
    string result;
    cin>>s;
    for(char c:s){
        if(c != ']'){
            sk.push(c);
        }else{
            char tmc = sk.top();
            sk.pop();
            stack<char> tmsk;
            string tms;
            while(!sk.empty() && tmc>='A' && tmc<='Z'){
                tmsk.push(tmc);
                tmc=sk.top();
                sk.pop();
            }
            while(!tmsk.empty()){
                tms+=tmsk.top();
                tmsk.pop();
            }
            if(tmc=='|'){
                tmc=sk.top();
                sk.pop();
            }
            // after get the tms; we need get the number
            int tmi=0;
            int i=0;
            while(!sk.empty() && tmc >= '0' && tmc <= '9'){
                tmi+=ctoi(tmc)*pow(10,i);
                tmc=sk.top();
                sk.pop();
                i++;
            }
            for(int i=0;i<tmi;i++){
                for(char c:tms){
                    sk.push(c);
                }
            }
            if(sk.top()=='['){
                sk.pop();
            }
        }
    }
    while(!sk.empty()){
        result+=sk.top();
        sk.pop();
    }
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i];
    }
    cout<<endl;
}