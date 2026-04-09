#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> v;
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            v.push_back(x);
        }
        cout << v[n - 1] << " ";
        for (long long i = 0; i < n - 1; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
The solution is the shifted one position of p.
i.e. q(1) = p(n), q(2) = p(1), q(3) = p(2), and so on.

If (i, j) != (1, n)
If p(i) + p(i+1) + ... + p(j) = q(i) + q(i+1) + ... + q(j)
Then all terms cancelled except the last term of LHS and
the first term of RHS. Which is impossible to be equals.
*/