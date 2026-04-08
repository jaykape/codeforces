n, k = [int(x) for x in input().split()]


def smallest_factor(int: n):
    if n == 1:
        return 1
    for i in range(2, n + 1):
        if n % i == 0:
            return i


factors = []
while n > 1:
    if len(factors) == k - 1:
        factors.append(n)
        break
    factors.append(smallest_factor(n))
    n //= smallest_factor(n)

if len(factors) < k:
    print(-1)
else:
    print(*factors)
