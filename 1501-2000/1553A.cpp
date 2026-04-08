#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n % 10 != 9)
            cout << n / 10 << endl;
        else
            cout << n / 10 + 1 << endl;
    }
    return 0;
}