#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int a, b, c;
        ss >> a >> b >> c;

        if (a == b)
            cout << c;
        else if (a == c)
            cout << b;
        else
            cout << a;

        cout << endl;
    }
    return 0;
}