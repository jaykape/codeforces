#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> v;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (int i = 1; i <= n - 2; i++)
        {
            if (v[i] == -1)
                v[i] = 0;
        }
        if (v[0] == -1 && v[n - 1] != -1)
            v[0] = v[n - 1];
        else if (v[0] != -1 && v[n - 1] == -1)
            v[n - 1] = v[0];
        else if (v[0] == -1 && v[n - 1] == -1)
        {
            v[0] = 0;
            v[n - 1] = 0;
        }
        cout << abs(v[0] - v[n - 1]) << endl;
        for (int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}