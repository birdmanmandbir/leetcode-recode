#include "lib/general.h"
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> input;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    for (int i = 0; i < q; i++) {
        int curQ;
        cin >> curQ;
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (input[i] >= curQ) {
                result++;
                input[i]--;
            }
        }
        cout << result << endl;
    }
}