// #include "/home/neil/Codes/leetcode/lib/general.h"
#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, V;
    cin >> N;
    cin >> V;
    vector<pair<int,int>> v;
    int tmp1, tmp2;
    for (int i = 0; i < N; i++){
        cin >> tmp1;
        cin >> tmp2;
        v.push_back({tmp1, tmp2});
    }
    vector<vector<int>> memory(N+1, vector<int>(V+1, 0));
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= V; j++){
            if (j-v[i-1].first<0){
                memory[i][j] = memory[i-1][j];
                continue;
            }
            memory[i][j] = max(memory[i-1][j], memory[i-1][j-v[i-1].first]+v[i-1].second);
        }
    }
    cout << memory[N][V] << endl;
}