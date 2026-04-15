#include <iostream>
#include <numeric>
typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n % 2 == 0)
        {
            for (ll i = 1; i <= n - 1; i += 2)
            {
                cout << i + 1 << " " << i << " ";
            }
        }
        else
        {
            cout << 1 << " ";
            for (ll i = 2; i <= n - 1; i += 2)
            {
                cout << i + 1 << " " << i << " ";
            }
        }
        cout << endl;
    }
}
