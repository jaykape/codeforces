#include <iostream>
using namespace std;

int main()
{
    long long n, m, a;
    cin >> n >> m >> a;
    long long h, k; // blocks need for each side
    h = n / a + (n % a + a - 1) / a;
    k = m / a + (m % a + a - 1) / a;
    cout << h * k;
    return 0;
}