#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long n;
        vector<long long> f, g;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            f.push_back(x);
        }
        for (int i = 0; i < n - 2; i++)
        {
            g.push_back((f[i + 2] + f[i] - 2 * f[i + 1]) / 2);
        }

        long long an = f[0], a1 = f[n - 1];
        for (int i = 0; i < n - 2; i++)
        {
            an -= (i + 1) * g[i];
            a1 -= (n - i - 2) * g[i];
        }
        an /= (n - 1);
        a1 /= (n - 1);

        cout << a1 << " ";
        for (auto x : g)
        {
            cout << x << " ";
        }
        cout << an << endl;
    }
    return 0;
}

/*

f(1) = a(2) + 2*a(3) + 3*a(4) + ... + (n-1)*a(n)
f(n-1) = (n-1)*a(1) + ... + 2*a(n-2) + a(n-1)


f(k+1) -  f(k) = a(1) + a(2) + ... + a(k) - a(k+1) - a(k+2) - ... - a(n)

g(k) = f(k+1) + f(k-1) - 2*f(k) = 2*a(k)


define for 2 <= k <= n - 1

*/