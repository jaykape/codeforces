#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s1, s2;
        cin >> n >> s1 >> s2;

        vector<int> freq(26, 0);
        for (char c : s1)
            freq[c - 'a'] += 1;
        for (char c : s2)
            freq[c - 'a'] -= 1;

        bool matches = true;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                cout << "NO\n";
                matches = false;
                break;
            }
        }
        if (matches)
            cout << "YES\n";
    }
    return 0;
}