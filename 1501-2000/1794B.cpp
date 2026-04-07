#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<long long> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            if (x == 1)
                x = 2;
            v.push_back(x);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i + 1] % v[i] == 0)
                v[i + 1] += 1;
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}