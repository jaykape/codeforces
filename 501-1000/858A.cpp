#include <iostream>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    cout << lcm(n, static_cast<long long>(pow(10, k)));
    return 0;
}