def separate_two(x: int):
    pow = 0
    while x % 2 == 0:
        pow += 1
        x //= 2
    return x, pow


for _ in range(int(input())):
    n = int(input())
    a = [int(x) for x in input().split()]
    b = []
    tot_pow = 0

    for x in a:
        y, p = separate_two(x)
        b.append(y)
        tot_pow += p

    tot_sum = sum(b) - max(b) + max(b)*(2 ** (tot_pow))

    print(tot_sum)
