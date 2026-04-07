#include <iostream>

using namespace std;

void printRow(int i, int m)
{
    for (int j = (i - 1) * m + 1; j <= i * m; j++)
    {
        cout << j << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n == 4 || n == 5)
        {
            printRow(2, m);
            printRow(4, m);
            printRow(1, m);
            printRow(3, m);
            if (n == 5)
                printRow(5, m);
        }
        else
        {
            for (int i = 1; i <= n; i += 2)
                printRow(i, m);
            for (int i = 2; i <= n; i += 2)
                printRow(i, m);
        }
    }
    return 0;
}
