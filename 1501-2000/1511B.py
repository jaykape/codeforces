for _ in range(int(input())):
    a, b, c = [int(z) for z in input().split()]
    if b == c:
        print(10 ** (a - 1), 10 ** (b - 1))
    else:
        print(10 ** (a - 1), 10 ** (b - 1) + 10 ** (c - 1))
