#include "lib/general.h"
void printVector(vector<int> &v){
    for (auto x:v){
        cout << x << "->";
    }
    cout << endl;
}
int main(){
    vector<int> a = {1,2,3};
    printVector(a);
    cout << "yes" << endl;
}