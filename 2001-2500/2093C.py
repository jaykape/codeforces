for _ in range(int(input())):
    x, k = [int(z) for z in input().split()]

    def is_prime(n: int):
        if n == 1:
            return False
        if n <= 3:
            return True
        if n % 2 == 0 or n % 3 == 0:
            return False
        i = 5
        while i*i <= n:
            if n % i == 0 or n % (i+2) == 0:
                return False
            i += 6
        return True

    ans = "NO"
    if k == 1:
        if is_prime(x):
            ans = "YES"
    elif x == 1:
        n = 0
        while k > 0:
            n += 10 ** (k - 1)
            k -= 1
        if is_prime(n):
            ans = "YES"
    print(ans)
