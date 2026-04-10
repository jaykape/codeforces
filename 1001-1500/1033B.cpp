
#include <iostream>

using namespace std;

bool isPrime(long long x)
{
    long long i = 2;
    if (x <= 3)
        return true;
    if (x % 2 == 0 || x % 3 == 0)
        return false;

    for (long long i = 5; i * i <= x; i += 6)
    {
        if (x % i == 0 || x % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        if (a > b + 1 || !isPrime(a + b))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}

// a^2 - b^2 = (a - b)(a + b)