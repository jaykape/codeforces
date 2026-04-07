#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<int> v;

        if (n % 2 == 0)
        {
            cout << "-1" << endl;
            continue;
        }

        if (n == 1)
        {
            cout << "1" << endl
                 << "1" << endl;
            continue;
        }

        n /= 2;

        while (n > 0)
        {
            if (n % 2 != 0)
                v.push_back(1);
            else
                v.push_back(0);
            n /= 2;
        }
        reverse(v.begin(), v.end());
        if (v.size() > 40)
        {
            cout << -1 << endl;
            continue;
        }
        cout << v.size() << endl;
        for (int x : v)
        {
            if (x == 1)
                cout << 2 << " ";
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
The maximum is 2^41 - 1
Any odd numbers less than that should work too.
*/