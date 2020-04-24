#include <vector>
#include <iostream>
using namespace std;
int main(){
    vector<int> input={1,2};
    input.emplace_back(3);
    input.push_back(2);
    vector<int> nv(input.begin(), input.end());
    vector<int>::iterator it = input.begin();
    int x = *it;
}