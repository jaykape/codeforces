#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, x;
        cin >> a >> b;
        if (a == 1)
            x = b * b;
        else if (b % a == 0)
            x = b * b / a;
        else
            x = lcm(a, b);
        cout << x << endl;
    }
    return 0;
}

/*
If a | b then b = ap and x = apq.
Note that aq will be bigger divisor than a.
So the only possible scenario is aq = b = ap.
Thus x = ap^2 = b * b / a.

If a ~|~ b then x = lcm(a, b).
Note that if not, then lcm(a, b) > b will be a greater divisor of x.
*/