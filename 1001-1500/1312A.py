for _ in range(int(input())):
    n, m = [int(x) for x in input().split()]
    print("YES" if n % m == 0 else "NO")
