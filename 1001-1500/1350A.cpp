#include <iostream>
using namespace std;
typedef long long ll;

ll smallest_div(ll n)
{
    if (n % 2 == 0)
    {
        return 2;
    }
    if (n % 3 == 0)
    {
        return 3;
    }
    for (ll i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0)
            return i;
        if (n % (i + 2) == 0)
            return i + 2;
    }
    return n;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0)
        {
            cout << n + k * 2 << endl;
            continue;
        }
        else
        {
            cout << n + (k - 1) * 2 + smallest_div(n) << endl;
        }
    }
    return 0;
}