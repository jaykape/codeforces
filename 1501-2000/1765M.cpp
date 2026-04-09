#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, a = 1;
        cin >> n;

        for (long long i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                a = n / i;
                break;
            }
        }
        cout << a << " " << n - a << endl;
    }
    return 0;
}

/*
Assuming a <= b.
So b is at least n/2.
If b is not divisible by a then lcm is at least n.
Note that the pair (1, n - 1) will gives lower gcd.

Considered a | b.
Any divisor a of n could give us a pair (a, n - a)
whose lcm is n - a. To minimize it, we just has to find
the largest divisor a of n.
*/