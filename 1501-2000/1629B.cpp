#include <iostream>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long l, r, k;
        cin >> l >> r >> k;
        long long n = r - l + 1;

        if (r == l)
        {
            if (r == 1)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
            continue;
        }

        long long odds = (r + 1) / 2 - l / 2;
        if (k >= odds)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

/*
This is equivalent to find the minimal operations such that
there is a prime p that divides every element in a.

Note that choosing p = 2 will always requires less operations,
since in any segment of size >= 2,
divisibleBy2(a) >= divisibleByp(a) for any p > 2.

If r - l + 1 is even then k >= (r - l + 1) / 2
If r - l + 1 is odd
    and l is even, then k >= (r - l + 1) / 2
    and l is odd, then k >= 1 + (r - l + 1) / 2

Edge cases
r = l then any k (except a = [1])
*/