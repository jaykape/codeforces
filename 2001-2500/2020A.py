for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    ans = 0
    if k == 1:
        print(n)
        continue
    while n > 0:
        ans += n % k
        n //= k
    print(ans)
