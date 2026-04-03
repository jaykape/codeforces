#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int count = 0;
    string ans = "NO";
    for (int i = 0; i < s.size(); i++)
    {
        count += 1;
        if (count >= 7)
        {
            ans = "YES";
            break;
        }
        if (i != s.size() - 1 && s[i] != s[i + 1])
        {
            count = 0;
        }
    }
    cout << ans << endl;
}