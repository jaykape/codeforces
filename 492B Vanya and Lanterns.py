import sys

number_of_lanterns, length = [int(x) for x in input().split()]
positions = [int(x) for x in input().split()]

positions.sort()

if number_of_lanterns == 1:
    p = positions[0]
    print(max(p-0, length-p))
    sys.exit()

max_distance = 0
for i in range(1, len(positions)):
    max_distance = max(max_distance, positions[i] - positions[i-1])

max_distance = max(max_distance/2, positions[0], length-positions[-1])
print(max_distance)
