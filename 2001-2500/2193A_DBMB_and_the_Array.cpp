#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s, x;
        cin >> n >> s >> x;

        int num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            s -= num;
        }

        string result;

        if (s < 0 || s % x != 0)
            result = "NO\n";
        else
            result = "YES\n";

        cout << result << endl;
    }
    return 0;
}