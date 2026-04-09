#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << lcm(a, b) << endl;
    }
    return 0;
}