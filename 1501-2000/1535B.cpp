#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll numPairs = 0, add = n - 1;

        vector<ll> v;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x % 2 == 0)
            {
                numPairs += add;
                add--;
            }
            else
            {
                v.push_back(x);
            }
        }

        for (ll i = 0; i < v.size(); i++)
        {
            for (ll j = i + 1; j < v.size(); j++)
            {
                if (gcd(v[i], v[j]) > 1)
                {
                    numPairs++;
                }
            }
        }

        cout << numPairs << endl;
    }
    return 0;
}