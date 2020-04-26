#include <iostream>
bool isPowerOfTwo(int n) {
        return n&(n-1)==0;
}
int main(){
    std::cout << isPowerOfTwo(2)<<std::endl;
    std::cout << (2&1) <<std::endl;
}