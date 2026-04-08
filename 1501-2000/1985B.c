#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 3)
        {
            printf("3\n");
        }
        else
        {
            printf("2\n");
        }
    }
    return 0;
}

/*
As n grows, the number of terms will be significantly main factor to maximize the function.
So for n >= some constant, we will answer x = 2.

n = 3
2
3

n = 4
2 + 4
3
4


n = 5
2 + 4
3
4
5

n = 6
2 + 4 + 6
3 + 6
4
5
6

As you can see, the only exception is n == 3.

*/