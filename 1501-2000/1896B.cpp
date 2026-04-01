#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<char> v(s.begin(),s.end());

        int firstA = -1, lastB = -1;
        for (int i = 0; i <= n - 1; i++) {
            if (v[i] == 'A') {
                firstA = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (v[i] == 'B') {
                lastB = i;
                break;
            }
        }
        int ans = 0;
        if (firstA != -1 && lastB != -1 && firstA < lastB) ans = lastB - firstA;
        cout << ans << endl;

    }
    return 0;
}

/*
Note that we will never move B to the right and A to the left.
So (if there is) any head BBB... and tail ...AAA they could be ignored.

Then we will prove that any pair of 
AXXXXXB will eventually be able to be swapped.

Let A...B be a sequence of at least length 3, (i,i+1) be the smallest pair that could not be swapped.
Assuming all operations are done.
Then either s(i) == B or s(i+1) == A.
Since (i-1,i) has been swapped, meaning s(i) == A.
Therefore s(i+1) == A.
By the assumption there will be at least one B on the right of i+1, considered the nearest,
i.e. ...AAAAAA...AAAB...

Then this B could be swapped down to s(i+1) and then s(i), s(i+1) == A, B could be sawapped.
A contradiction
*/