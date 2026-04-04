#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, prev, count = 1, maxCount = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        count += 1;
        if (i > 0 && prev <= x)
            maxCount = max(count, maxCount);
        else
            count = 1;
        prev = x;
    }
    cout << maxCount;
    return 0;
}