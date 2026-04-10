#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        for (long long i = 2; i <= n + 1; i++)
        {
            if (n % i != 0)
            {
                cout << i - 1 << endl;
                break;
            }
        }
    }
    return 0;
}

/*
If [l,r] is a solution of maximum length,
then the interval I = [1, r-l+1] will be a solution too.
Note that for any i in I,
since I has consecutive elements length >= i
there will be an element in [l,r] such that divisible by i,
and hence n is divisible by i.

So we will loop from i = 2, increment += 1 to check the first k
such that n is not divisible by k, and the answer is k - 1.
*/