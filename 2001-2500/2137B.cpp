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

        if (n == 2)
        {
            int x, y;
            cin >> x >> y;
            if (x == 1)
                cout << 2 << " " << 1 << endl;
            else
                cout << 1 << " " << 2 << endl;
            continue;
        }
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            if (x != n)
            {
                cout << n - x << " ";
            }
            else
                cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}