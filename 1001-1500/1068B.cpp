#include <iostream>
using namespace std;
typedef long long ll;

ll countDivisors(ll n)
{
    if (n <= 0)
        return 0;

    ll count = 1;

    for (ll p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            int exp = 0;
            while (n % p == 0)
            {
                n /= p;
                exp++;
            }
            count *= (exp + 1);
        }
    }

    if (n > 1)
        count *= 2;

    return count;
}

int main()
{
    ll b;
    cin >> b;

    cout << countDivisors(b);

    return 0;
}
