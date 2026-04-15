#include <iostream>
#include <numeric>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    if (n == 2)
    {
        cout << 1 << endl
             << 1;
        return 0;
    }
    ll prod = 1, length = 0;
    for (ll i = 1; i < n - 1; i++)
    {
        if (gcd(i, n) == 1)
        {
            prod *= i;
            prod %= n;
            length += 1;
        }
    }
    if (prod % n == 1)
    {
        cout << length << endl;
        for (ll i = 1; i < n - 1; i++)
        {
            if (gcd(i, n) == 1)
            {
                cout << i << " ";
            }
        }
    }
    else
    {
        cout << length + 1 << endl;
        for (ll i = 1; i < n; i++)
        {
            if (gcd(i, n) == 1)
            {
                cout << i << " ";
            }
        }
    }
}
