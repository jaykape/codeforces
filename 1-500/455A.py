n = int(input())
a = [int(x) for x in input().split()]
m = max(a)
max_scores = []
amount = {i: 0 for i in range(1, m+1)}
for i in a:
    amount[i] += i
max_scores.append(amount[1])
if m > 1:
    max_scores.append(max(amount[1], amount[2]))
if m > 2:
    for i in range(3, m+1):
        max_scores.append(max(max_scores[-1], max_scores[-2]+amount[i]))
print(max(max_scores[-1], max_scores[-2]))
