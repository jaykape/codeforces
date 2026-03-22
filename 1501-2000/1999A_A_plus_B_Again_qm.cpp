#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, ans;
        cin >> n;
        ans = n / 10 + n % 10;
        cout << ans << endl;
    }

    return 0;
}