#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (found)
                break;
            for (int j = i + 1; j < n; j++)
            {
                if (gcd(v[i], v[j]) <= 2)
                {
                    found = true;
                    break;
                }
            }
        }
        if (found)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}