#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, ans = 0;
        cin >> n;
        while (n != 1)
        {
            if (n % 6 == 0)
            {
                ans += 1;
                n = n / 6;
            }
            else if (n % 3 == 0)
            {
                ans += 2;
                n = n / 3;
            }
            else
            {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}