l = [ 10 ** i + 1 for i in range(1,20) ]
for _ in range(int(input())):
    n = int(input())
    ans = 0
    ansl = []
    for i in range(19):
        if n < l[i]:
            break
        if n % l[i] == 0:
            ans += 1
            ansl = [str(n//l[i])] + ansl
    print(ans)
    if ansl:
        print(" ".join(ansl))
    