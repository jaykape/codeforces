#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> k;
        cout << k - 1 << endl;
    }
    return 0;
}

/*
x! + (x - 1)! = (x - 1)!(x + 1)
So x := k - 1 will gives a multiple of k.
*/