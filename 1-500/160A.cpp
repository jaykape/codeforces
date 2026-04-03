#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    long long n;
    vector<long long> v;
    cin >> n;
    long long k, sum = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> k;
        sum += k;
        v.push_back(k);
    }
    sort(v.begin(), v.end(), greater<long long>());
    long long ans = 0, sum2 = 0;
    for (long long i = 0; i < n; i++)
    {
        sum2 += v[i];
        sum -= v[i];
        ans += 1;
        if (sum2 > sum)
        {
            cout << ans;
            break;
        }
    }
    return 0;
}