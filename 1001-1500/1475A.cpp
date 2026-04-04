#include <iostream>

using namespace std;

bool isPowerOf2(long long n)
{
    return (n & (n - 1)) == 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (isPowerOf2(n))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}