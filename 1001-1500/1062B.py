n = int(input())


def smallestDivisor(n: int):
    for i in [2, 3]:
        if n % i == 0:
            return i

    i = 5
    while i * i <= n:
        if n % i == 0:
            return i
        if n % (i + 2) == 0:
            return i + 2

        i += 6

    return n


ans = 1
powers = []

while n > 1:
    p = smallestDivisor(n)
    ans *= p

    power = 0
    while n % p == 0:
        power += 1
        n //= p

    powers.append(power)


u = max(powers)
v = min(powers)
ops = 0

if u != v or (u & (u - 1)) != 0:
    ops += 1

if u == 1:
    print(ans, 0)
else:
    notpow = False
    while u > 1:
        if u % 2 != 0:
            notpow = True
        ops += 1
        u //= 2

    if notpow:
        ops += 1

    print(ans, ops)
