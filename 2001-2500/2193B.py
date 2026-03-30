for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = []
    rev = []
    i = 0
    j = n - 1
    while i < n:
        if a[i] == n - i:
            ans.append(a[i])
            i += 1
        else:
            break
    j = i
    while j < n:
        if a[j] != n - i:
            rev.append(a[j])
            j += 1
        else:
            rev.append(a[j])
            j += 1
            break
    k = j
    ans += reversed(rev)
    while k < n:
        ans.append(a[k])
        k += 1
    ans = [str(x) for x in ans]
    print(" ".join(ans))
