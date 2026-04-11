#include <utility>
typedef long long ll;
using namespace std;

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

// Return smallest prime factor of n and its power in n.
// #include <utility>  // std::pair

std::pair<ll, ll> smallestPrimeFactor(ll n)
{
    if (n <= 1)
        return {-1, 0};

    for (ll p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            ll exp = 0;
            while (n % p == 0)
            {
                n /= p;
                exp++;
            }
            return {p, exp};
        }
    }

    return {n, 1}; // n itself is prime
}