#include <stdio.h>

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);

    int n = (A < B) ? A : B;

    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        ans *= i;
    }
    printf("%d", ans);
    return 0;
}

// A! always divisible by B! for any B <= A.