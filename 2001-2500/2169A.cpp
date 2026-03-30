#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        int lsum = 0, rsum = 0;
        cin >> n >> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > a)
                rsum += 1;
            else if (x < a)
                lsum += 1;
        }
        if (lsum > rsum)
            b = a - 1;
        else
            b = a + 1;
        cout << b << endl;
    }
    return 0;
}