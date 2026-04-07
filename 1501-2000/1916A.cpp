#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v;
        bool done = false;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        int z = 2023;
        for (int i = 0; i < n; i++)
        {
            if (z % v[i] != 0)
            {
                done = true;
                break;
            }
            else
                z /= v[i];
        }
        if (done)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << z << " ";
            while (k > 1)
            {
                cout << "1 ";
                k--;
            }
            cout << endl;
        }
    }
    return 0;
}

/*
2023 = 7 * 17 * 17
*/