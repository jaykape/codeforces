#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }

    int max_height = 0;
    for (auto &p : freq)
    {
        max_height = max(max_height, p.second);
    }

    int towers_number = freq.size();

    cout << max_height << " " << towers_number << endl;

    return 0;
}