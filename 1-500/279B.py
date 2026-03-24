n, t = [int(x) for x in input().split()]
times = [int(x) for x in input().split()]
max_read = 0
left = 0
curr_sum = 0
for right in range(n):
    curr_sum += times[right]
    while curr_sum > t:
        curr_sum -= times[left]
        left += 1
    max_read = max(max_read, right - left + 1)

print(max_read)
