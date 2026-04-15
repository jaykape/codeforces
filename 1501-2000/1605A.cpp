
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll n = a + b - 2 * c;
        if (n % 3 == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
    }
    return 0;
}