for _ in range(int(input())):
    a, b = [int(x) for x in input().split()]
    count = 0
    while a > 0 and b > 0:
        if a >= b:
            count += a//b
            a = a % b
        else:
            count += b//a
            b = b % a

    print(count)
