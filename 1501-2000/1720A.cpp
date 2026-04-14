#include <iostream>
#include <numeric>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        int ans;

        if (a == 0 && c == 0)
            ans = 0;
        else if (a == 0 || c == 0)
            ans = 1;
        else
        {

            ll g = gcd(a, b);
            ll h = gcd(c, d);

            a /= g;
            b /= g;
            c /= h;
            d /= h;

            if (a == c && b == d)
                ans = 0;

            else if ((a % c == 0 && d % b == 0) || (c % a == 0 && b % d == 0))
                ans = 1;
            else
                ans = 2;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
Note that by multiply cb to a/b and ad to c/d, they become equals.
So we have to find cases where 0 or 1 operation is enough.

0 is obvious, just calculate and compare.

for 1, meaning ax
*/