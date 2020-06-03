#include <bits/stdc++.h>
using namespace std;
vector<int> path;
int res = 0;
void printVector(vector<int> &v){
    for (auto x:v){
        cout << x << "->";
    }
    cout << endl;
}
void dfs(int pos, int remainPerson, vector<int>& buildings, int D)
{
    int n = buildings.size();
    if (remainPerson == 0) {
        res++;
        // printVector(path);
        return;
    }
    if (pos >= n) {
        return;
    }
    for (int i = pos; i < n; i++) {
        if (path.size() == 0 || buildings[i] - buildings[path[0]] <= D) {
            path.push_back(i);
            dfs(i + 1, remainPerson - 1, buildings, D);
            path.pop_back();
        }
        if (buildings[i] - buildings[path[0]] > D){
            return;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    int N, D;
    cin >> N >> D;
    vector<int> buildings(N);
    for (int i = 0; i < N; i++) {
        cin >> buildings[i];
    }
    dfs(0, 3, buildings, D);
    cout << res << endl;
}