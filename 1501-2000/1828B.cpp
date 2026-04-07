#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, ans = 0;
        cin >> n;

        for (long long i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            if (x != i)
            {
                ans = gcd(ans, abs(x - i));
            }
        }
        cout << ans << endl;
    }
    return 0;
}