#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (n + 1)/2 << endl;
        int l = 1, r = n * 3;
        while (l < r) {
            cout << l << " " << r << endl;
            l += 3;
            r -= 3;
        }
    }
    return 0;
}