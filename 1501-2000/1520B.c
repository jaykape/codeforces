#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    long long arr[9];
    arr[0] = 1;
    for (int i = 1; i < 9; i++)
    {
        arr[i] = arr[i - 1] * 10 + 1;
    }

    while (t--)
    {
        long long n, count = 0;
        scanf("%lld", &n);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 1; j < 10; j++)
            {
                if (n >= j * arr[i])
                {
                    count += 1;
                }
                else
                    break;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}