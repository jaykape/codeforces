#include <iostream>

using namespace std;

int countPrimeDivisors(int n)
{
    int count = 0, m = n;
    for (int i = 2; i < n; i++)
    {
        if (m % i == 0)
        {
            count += 1;
            while (m % i == 0)
                m = m / i;
        }
    }
    return count;
}

int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (countPrimeDivisors(i) == 2)
            ans += 1;
    }
    cout << ans;

    return 0;
}