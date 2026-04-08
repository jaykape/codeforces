#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        cout << (n - (n % 2)) / 2 << endl;
    }
    return 0;
}

/*
If n is even, then the pair (n, n/2) produce the maximum gcd = n/2.
For any a < b <= n, let g = gcd(a, b).
If g > n/2, then b >= 2*g > n which is a contradiction.

For the case of n odd, we still have gcd(n-1, (n-1)/2) = (n-1)/2.
Any pair (n, a) will have less gcd since gcd(n, a) <= a <= n/3.

This method will works for edge cases of small n too.
*/