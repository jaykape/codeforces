for _ in range(int(input())):
    x = int(input())
    ans = "NO"
    for i in range(1, 11):
        if x % 11 == i and x >= 111 * i:
            ans = "YES"

    if x % 11 == 0:
        ans = "YES"

    print(ans)
