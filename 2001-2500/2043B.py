for _ in range(int(input())):
    n, d = [int(x) for x in input().split()]
    ans = [1]

    if d % 3 == 0 or n >= 3:
        ans.append(3)

    if d == 5:
        ans.append(5)

    if d % 7 == 0 or n >= 3:
        ans.append(7)

    if d % 9 == 0 or n >= 6 or (d % 3 == 0 and n >= 3):
        ans.append(9)

    print(*ans)
