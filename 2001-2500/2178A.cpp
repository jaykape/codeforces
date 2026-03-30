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
        cin >> s;
        int countY = 0;
        bool invalid = false;

        for (char c : s)
        {
            if (c == 'Y' && ++countY > 1)
            {
                cout << "NO\n";
                invalid = true;
                break;
            }
        }
        if (invalid)
            continue;
        cout << "YES\n";
    }
    return 0;
}