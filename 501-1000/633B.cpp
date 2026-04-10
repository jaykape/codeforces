#include <iostream>

using namespace std;

long long fiveInFactorial(long long n)
{
    long long temp = n, sumDigit = 0;
    while (temp > 0)
    {
        sumDigit += temp % 5;
        temp /= 5;
    }
    return (n - sumDigit) / 4;
}

int main()
{
    long long m, n;
    cin >> m;
    bool done = false;

    for (long long i = (4 * m) - ((4 * m) % 5); i <= 5 * m; i += 5)
    {
        if (fiveInFactorial(i) == m)
        {
            n = i;
            cout << "5" << endl;
            cout << n << " " << n + 1 << " " << n + 2 << " " << n + 3 << " " << n + 4 << endl;
            done = true;
            break;
        }
    }

    if (!done)
    {
        cout << 0 << endl;
    }

    return 0;
}

/*
This is equivalent to find the n such that n! has exactly m of 5's.
Let S(n) be the number of 5's of n.

For each n, write n as a(k)5^k + ... + a(1)5 + a(0)

fl(n/5) = a(k)5^(k-1) + ... + a(2)5 + a(1)
...
fl(n/5^k) = a(k)

(5 - 1)S(n) = a(k)(5^k - 1) + a(k-1)(5^(k-1) - 1) + ... + a(2)(5^2 - 1) + a(1)(5 - 1) + a(0)(1 - 1)

4S(n) = n - (sum of digits in n base 5)

So for each m, we will start from i = 4 * m and iterate up.
Note that it will start with some multiple of 5,
so we will start with 4 * m / 5 then iterate i += 5.
*/