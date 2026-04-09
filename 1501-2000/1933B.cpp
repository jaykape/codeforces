#include <iostream>
#include <set>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, sum = 0;
        set<int> residues;
        cin >> n;

        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;

            sum += x;
            sum %= 3;
            residues.insert(x % 3);
        }

        int moves;
        if (sum == 0)
        {
            moves = 0;
        }
        else if (residues.count(sum) >= 1 || sum == 2)
        {
            moves = 1;
        }
        else
        {
            moves = 2;
        }
        cout << moves << endl;
    }
    return 0;
}