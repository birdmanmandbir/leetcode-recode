#include <iostream>
using namespace std;

int main(){
    pair<int, int> a={1,2};
    pair<int, int> b={3,4};

    a.swap(b);
    cout<<a.first;
    swap(a,b);
    cout<<a.first;
    // 3 1
}