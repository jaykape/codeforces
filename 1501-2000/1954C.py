for _ in range(int(input())):
    x = [int(z) for z in input()]
    y = [int(z) for z in input()]

    n = len(x)
    i = 0
    while (i < n and x[i] == y[i]):
        i += 1

    if i == n:
        pass
    else:
        if x[i] > y[i]:
            for i in range(i+1, n):
                if (x[i] > y[i]):
                    x[i], y[i] = y[i], x[i]
        else:
            for i in range(i+1, n):
                if (x[i] < y[i]):
                    x[i], y[i] = y[i], x[i]

    print(''.join(map(str, x)))
    print(''.join(map(str, y)))
