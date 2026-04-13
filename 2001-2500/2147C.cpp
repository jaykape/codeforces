#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        string s;
        cin >> n >> s;

        bool ok = true;
        bool curr = (s[0] == '1'); // curr true means the current segment has to be checked by cnt % 2
        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
                cnt++;
            if (i == 0)
                continue;
            if (s[i - 1] == s[i] && s[i] == '0')
                curr = false;
            if (s[i - 1] == s[i] && s[i] == '1')
            {
                if (curr && cnt % 2 == 1)
                {
                    ok = false;
                }
                curr = true;
                cnt = 0;
            }
        }

        if (curr && cnt % 2 == 1 && s[n - 1] == '1')
            ok = false;

        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}