for _ in range(int(input())):
    n, k = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]

    done = False
    ans = "YES"
    while a != [0]*n and not done:
        count = 0
        for i in range(n):
            if a[i] % k not in {0, 1}:
                ans = "NO"
                done = True
                break
            if a[i] % k == 1:
                count += 1
            a[i] //= k

        if count > 1:
            ans = "NO"
            done = True

    print(ans)
