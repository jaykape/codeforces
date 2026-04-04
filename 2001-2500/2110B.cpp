#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string ans = "NO";
        long long balance = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (i == s.size() - 1)
                break;
            if (s[i] == '(')
                balance += 1;
            else
                balance -= 1;
            if (balance == 0)
            {
                ans = "YES";
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}