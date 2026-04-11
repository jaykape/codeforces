# This is not pass the test due to the Python's limitation (got TLE)

n, k = [int(x) for x in input().split()]


def divisors(x: int):
    small_divisor = [1]
    large_divisor = [x]

    i = 2
    while i * i < x:
        if (x % i == 0):
            small_divisor.append(i)
            large_divisor.append(x//i)
        i += 1

    if i * i == x:
        small_divisor.append(i)

    reversed(large_divisor)

    return small_divisor + large_divisor


d = divisors(n)

if len(d) >= k:
    print(d[k - 1])
else:
    print(-1)
