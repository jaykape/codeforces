n = int(input())
for i in range(n):
    ticket = input()
    lsum, rsum = 0, 0
    for i in ticket[:3]:
        lsum += int(i)
    for i in ticket[3:]:
        rsum += int(i)
    if lsum == rsum:
        print('yes')
    else:
        print('no')
