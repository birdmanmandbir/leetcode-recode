#include <vector>
#include <iostream>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int len1 = a.size();
    int len2 = b.size();
    int i = 0;
    int j = 0;
    while(i<len1 && j<len2){
        if (a[i] < b[j]){
            res.push_back(a[i]);
            i++;
        }else{
            res.push_back(b[j]);
            j++;
        }
    }
    while (i<len1){
        res.push_back(a[i]);
        i++;
    }
    while (j<len2){
        res.push_back(b[j]);
        j++;
    }
    return res;
}

int main(){
    vector<int> a = {1,4,5};
    vector<int> b = {2,7,8,9,10};
    vector<int> res = merge(a, b);
    for (auto x: res){
        cout << x << "->" ;
    }
    cout << endl;
}