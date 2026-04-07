#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> lucky = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

    int n;
    string ans = "NO";
    cin >> n;
    for (int x : lucky)
    {
        if (n % x == 0)
        {
            ans = "YES";
            break;
        }
    }
    cout << ans;

    return 0;
}