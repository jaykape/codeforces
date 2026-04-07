from math import gcd

for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    d = {}
    b = []
    for i in range(n-1, -1, -1):
        if a[i] not in d:
            d[a[i]] = i
            b.append(a[i])
    m = len(b)
    done = False
    ans = 0
    for i in range(m):
        for j in range(i, m):
            if j == i and b[j] != 1:
                continue
            if gcd(b[i], b[j]) == 1:
                ans = max(ans, d[b[i]] + d[b[j]] + 2)
                done = True
    if done:
        print(ans)
    else:
        print(-1)
