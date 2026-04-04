#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = v[n - 1] - v[0];
    for (int i = n; i < m; i++)
    {
        ans = min(v[i] - v[i - n + 1], ans);
    }
    cout << ans;

    return 0;
}