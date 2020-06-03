#include <bits/stdc++.h>
using namespace std;
#define BIG_NUM 835672545
long long res = 0;
string article;
vector<string> dict;
vector<vector<int>> dp;
vector<vector<long long>> dp2;
// ioa: 在i处之前已经保证可以被字典分开
long long dfs(int indexOfArticle){
    int size = article.size();
    long long count = 0;
    if (indexOfArticle>=article.size()){
        res++;
        count++;
        return count;
    }
    for (int j = 0; j < dict.size(); j++){
        if (dp2[indexOfArticle][j]>0){
            count+=dp2[indexOfArticle][j];
            continue;
        }
        string d = dict[j];
        if(d.size()>size-indexOfArticle){
            continue;
        }
        int end = indexOfArticle + d.size();
        bool match = true;
        for (int i = indexOfArticle; i < end; i++){
            if (dp[indexOfArticle][j] == 1){
                break;
            }
            if (article[i]!=d[i-indexOfArticle] || dp[indexOfArticle][j] == -1){
                match = false;
                break;
            }
        }
        if (match) {
            dp[indexOfArticle][j] = 1;
            count+=dfs(end);
        }
        dp2[indexOfArticle][j] = count;
    }
    return count;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> article;
    int dictSize;
    cin >> dictSize;
    string tmp;
    for (int i = 0; i < dictSize; i++){
        cin >> tmp;
        dict.push_back(tmp);
    }
    dp = vector<vector<int>>(article.size(), vector<int> (dict.size(), 0));
    dp2 = vector<vector<long long>>(article.size(), vector<long long> (dict.size(), -1));
    cout << dfs(0)%BIG_NUM << endl;
    // cout << res % BIG_NUM << endl;
}