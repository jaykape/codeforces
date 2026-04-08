#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long k, x;
        scanf("%lld %lld", &k, &x);
        printf("%lld\n", 9 * (k - 1) + x);
    }
    return 0;
}

/*
Note that each 10^u = 1 (mod 9).
So S(m) is exactly m modulo 9.
*/