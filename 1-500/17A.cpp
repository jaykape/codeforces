#include <iostream>
#include <vector>

using namespace std;

int isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n, k, count = 0;
    cin >> n >> k;

    vector<int> primes, expressible;
    for (int i = 1; i < 500; i++)
    {
        if (isPrime(i))
            primes.push_back(i);
    }
    for (int i = 1; i < primes.size(); i++)
    {
        int e = primes[i] + primes[i - 1] + 1;
        if (isPrime(e))
        {
            expressible.push_back(e);
        }
    }
    for (int i = 0; i < expressible.size(); i++)
    {
        if (expressible[i] <= n)
            count += 1;
        else
            break;
    }
    if (count >= k)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}