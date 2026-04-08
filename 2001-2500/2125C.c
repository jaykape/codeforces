#include <stdio.h>

long long count_divisible(long long left, long long right, long long m)
{
    return (right / m) - (left - 1) / m;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long l, r;
        scanf("%lld %lld", &l, &r);

        // Inclusion-exclusion: + for single primes, - for pairwise LCMs, + for triple, etc.
        long long moduli[] = {2, 3, 5, 7, 6, 10, 14, 15, 21, 35, 30, 42, 70, 105, 210};
        int signs[] = {1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, 1, 1, -1};
        int num_terms = sizeof(moduli) / sizeof(moduli[0]);

        long long count = 0;
        for (int j = 0; j < num_terms; j++)
        {
            count += signs[j] * count_divisible(l, r, moduli[j]);
        }

        long long ans = r - l + 1 - count;

        printf("%lld\n", ans);
    }
    return 0;
}

/*
The number of numbers between l and r inclusive is r - l + 1.
We have to count all numbers that is divisible by 2 or 3 or 5 or 7,
then subtract it from r - l + 1.
*/