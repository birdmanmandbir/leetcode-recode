#include "../lib/general.h"
void reverseNumber (unsigned char* c){
    *c = *c>>4 | *c<<4;
    *c = (*c & 0xcc)>>2 | (*c & 0x33)<<2;
    *c = (*c & 0xaa)>>1 | (*c & 0x55)<<1;
}
int main(){
    unsigned char* p;
    unsigned char c= 0b10110111;
    p=&c;
    reverseNumber(p);
    // This is unary addition that will promote the unsigned char to give you the actual number representation.
    cout << +c << endl;
    printf("%b\n", c);
}