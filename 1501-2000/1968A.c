#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", x - 1);
    }
    return 0;
}

/*
Let (x, y) be a solution.
g = gcd(x, y), x = dX, y = dY.
So g + y = d(1+Y).
Let's see some obvious bounds.
Since Y < X, g + y <= d(1 + (X - 1)) = x.

Hence we could pick y = x - 1 and get the optimal solution x for any x.
*/