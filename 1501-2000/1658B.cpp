#include <iostream>

using namespace std;

long long factMod(int x)
{
    long long fact = 1;
    for (int i = 1; i <= x; i++)
    {
        fact *= i;
        if (fact > 1000000000)
        {
            fact %= 998244353;
        }
    }
    return (fact * fact) % 998244353;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 1)
            cout << 0 << endl;
        else
            cout << factMod(n / 2) << endl;
    }
    return 0;
}