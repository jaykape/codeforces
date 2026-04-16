#include <iostream>
#include <numeric>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (gcd(a, b) == 1 ? "finite" : "infinite") << endl;
    }
    return 0;
}