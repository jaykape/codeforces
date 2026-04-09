#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<long long> a;
        long long g = 0;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;

            a.push_back(x);
            g = gcd(g, x);
        }

        int ans;
        if (g == 1)
        {
            ans = 0;
        }
        else if (gcd(g, n) == 1)
        {
            ans = 1;
        }
        else if (gcd(g, n - 1) == 1)
        {
            ans = 2;
        }
        else
        {
            ans = 3;
        }
        cout << ans << endl;
    }
    return 0;
}

/*
Note that an operation on index i is equivalent to passing i into
the computation of gcd of the array.

Also note that the gcd of consecutive numbers is 1.
So at most we pay the cost 1 + 2 = 3 to add index n and n - 1 and got gcd = 1.

There are three cases to pay lower:
1. add only n
2. add only n - 1
3. do nothing
*/