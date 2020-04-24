#include "lib/general.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
class x {
};

class y {
    virtual int xx();
};
int main()
{
    std::cout << sizeof(x) << "\n";
    std::cout << sizeof(y) << "\n";
    cout << pow(10, 3) << "\n";
    cout << 123 << "\n";
    cout << -1 % 5 << endl;
    vector<int> x={1,2};
    // cout<<*x.end()<<endl;
    // pair<int, int> a = { 1, 2 };
    // pair<int, int> b = { 1, 2 };
    // cout << (a + b).first << endl;
    cout << abs(-1) << endl;
    cout << (*x.begin()) << "x begin" << endl;
}