for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]

    maxg = 0
    for i in range(n):
        sumi = sum(a[:i+1])
        maxi = sumi
        for j in range(i+1, n):
            sumi += a[j] - a[j-i-1]
            maxi = max(maxi, sumi)
        maxi /= i + 1
        maxg = max(maxg, maxi)

    print(int(maxg))
