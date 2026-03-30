#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w, ans;
        cin >> n >> w;
        ans = (n / w) * (w - 1) + (n % w);
        cout << ans << endl;
    }
    return 0;
}