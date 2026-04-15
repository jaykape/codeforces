from math import lcm

for _ in range(int(input())):
    s, t = input(), input()
    m, n = len(s), len(t)
    l = lcm(m, n)
    if s * (l//m) == t * (l//n):
        print(s * (l//m))
    else:
        print(-1)
