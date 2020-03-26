#include <iostream>
#include <math.h>
#include <string>
using namespace std;
class x{
};

class y{
    virtual int xx();
};
int main(){
    std::cout<<sizeof(x)<<"\n";
    std::cout<<sizeof(y)<<"\n";
    cout<<pow(10,3)<<"\n";
    cout<<123<<"\n";
    cout<<-1%5;
}