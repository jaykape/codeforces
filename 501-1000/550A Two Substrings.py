import sys

s = input()
n = len(s)
if n < 4:
    print("NO")
    sys.exit()
d = {x: 0 for x in {"AB", "BA", "ABA", "BAB"}}
for i in range(n-1):
    s2 = s[i:i+2]
    if s2 == "AB" or s2 == "BA":
        d[s2] += 1
for i in range(n-2):
    s3 = s[i:i+3]
    if s3 == "ABA" or s3 == "BAB":
        d[s3] += 1
c1 = d["AB"] == 0 or d["BA"] == 0
c2 = d["AB"] == 1 and d["BA"] == 1 and (d["ABA"] == 1 or d["BAB"] == 1)
c3 = d["AB"] == 2 and d["BA"] == 1 and d["ABA"] == 1 and d["BAB"] == 1
c4 = d["AB"] == 1 and d["BA"] == 2 and d["ABA"] == 1 and d["BAB"] == 1
if c1 or c2 or c3 or c4:
    print("NO")
else:
    print("YES")
