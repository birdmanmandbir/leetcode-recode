#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<vector<int>> vv;
    vector<int> v = { 1, 2, 3 };
    vv.push_back(v);
    v[2]=4;
    for(auto const& cc: vv){
        for(auto const& c: cc){
            cout << c << " ";
        }
    }
    cout << endl;
}