#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1)
        {
            cout << -1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 23 << endl;
            continue;
        }
        cout << 22;
        for (long long i = 1; i <= n - 2; i++)
        {
            cout << 3;
        }
        cout << endl;
    }
    return 0;
}

/*
n   s
2   23
3   223
4   2233
5   22333

Note that all of them = 2 + 2 + 3 + 3 + 3 + ... = 1 (mod3)

*/